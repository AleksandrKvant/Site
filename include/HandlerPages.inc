<?php
If (isset($ActivUser) && $Str_Page === "Авторизация")
	header("Location: index.php" . getNewGetForAdresStroka(), True);
Elseif (isset($ActivUser) && $Str_Page === "Регистрация")
	header("Location: newuserinfo.php" . getNewGetForAdresStroka(), True);

$All_Message->add_Message("Авторизация", "=Авторизация===================================", 0 ,"Разработчик");
If (isset($ActivUser)) {

	$All_Message->add_Message("Авторизация", "Ник: '" . $ActivUser->S_User_Nik . "', Короткое имя: '" . $ActivUser->S_ShortName . "', Полное имя: '" . $ActivUser->S_FullName . "', СИД пипла: '"
			. $ActivUser->getPeopleID() . "', ПИД юзера: '" . $ActivUser->_P_ID . "', СИД юзера: '" . $ActivUser->getUserID() . "'", 0, "Разработчик");
	$Void_Perem = $ActivUser->getCategory();
	$str_1 = "";
	If (is_array($Void_Perem)) {
		For ($i = 0; $i < count($Void_Perem); $i++){
			If ($i === 0) $str_1 = $Void_Perem[$i];
			Else $str_1 .= ", " . $Void_Perem[$i];
		}
	}
	$All_Message->add_Message("Приложение", "Категории пользователя: '" . $str_1 . "'", 0, "Разработчик");

	If ($ActivUser->isDeveloper())
		$All_Message->add_Message("Приложение", "Это разработчик!", 0, "Разработчик");
	Else
		$All_Message->add_Message("Приложение", "Это не разработчик!", 0, "Разработчик");

	$Void_Perem = $ActivUser->getEMail();
	$str_1 = "";
	If (is_array($Void_Perem)) {
		For ($i = 0; $i < count($Void_Perem); $i++){
			If ($i !== 0)
				$str_1 .= ", ";

			$str_1 .= $Void_Perem[$i]['Адрес'];

			If ($Void_Perem[$i]['Основной'] === True)
				$str_1 .= ' Основной';
			Else
				$str_1 .= ' Вторичный';
			If ($Void_Perem[$i]['Подтвержден'] === True)
				$str_1 .= ' Подтвержден';
			Else
				$str_1 .= ' Не подтвержден';
		}
	}
	$All_Message->add_Message("Приложение", "Адреса электронной почты: '" . $str_1 . "'", 0, "Разработчик");

	unset($Void_Perem, $str_1);
}
Else {
	$All_Message->add_Message("Авторизация", "Пользователь неопределен", 0 ,"Разработчик");
	if ($Str_Page === "Личный кабинет" || $Str_Page === "Настройки системы" || $Str_Page === "Мои ссылки"
			|| $Str_Page === "Выбор картинки банера") {
		$Str_Page = "Стартовая";
		header("Location:index.php" . getNewGetForAdresStroka(), true);
	}
}

$All_Message->add_Message("Авторизация", "Авторизация пройдена. Прошло времени: " . (microtime() - $TimeStartSys) . " мксек.", 0, "Разработчик");
$All_Message->add_Message("Авторизация", "=Авторизация===================================", 0 ,"Разработчик");
If ($All_Message->Log_GlobalError)
	$Str_Page = "Стартовая";
If (strlen(trim($Str_Page)) == 0)
	$Str_Page = "Стартовая";

If (isset($SystemValue) && $SystemValue->getCounter()['Use'] == True) {
	$Log_ToSchetchik = In_Base_Object($MainConnect, $All_Message, $Arr_Sess['S_ThisIPUser'], $Arr_Sess['S_Forwarded'], Str_HostName, time());
	$Mas_CountRecord = From_Base_Object($MainConnect, $All_Message, Str_HostName, time());
}

// Инициализирую построитель страницы
If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
	include_once($SystemValue->getIncludeDir() . 'ClassBasePage.inc');
Else
	include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassBasePage.inc');

$PrintPage = New BasePage($Str_Page);

If (isset($ActivUser) && is_object($ActivUser) && $Str_Page === "Свойства банера" && $ActivUser->getUserID() === $_Obj_Baner->_S_IDManager) {
	$PrintPage->_Bool_ReadOnly = False;
}

// Предзаполнение свойств построителя страницы
$PrintPage->_Str_AdresPage = "";
$PrintPage->_Str_PageIdent = $Str_Page;
$PrintPage->_Str_GETRole = $Str_GetRole;
$PrintPage->_Time_StartSys = $TimeStartSys;
$PrintPage->_Arr_Post = $Arr_Post;
$PrintPage->_Arr_Get = $Arr_Get;

$Str_Description = "";
$_Arr_Baners = array();

If (!$All_Message->Log_GlobalError) {

	If (isset($ActivUser)) {
		$Arr_Sess['S_IDUser'] = $ActivUser->_P_ID;
		$Arr_Sess['B_UsePassword'] = false;
	}
	Elseif (!$Str_Page === "Информация о регистрации") {
	    $_SESSION = array();
		$All_Message->add_Message("LogOn", "Вы не авторизованы. При необходимости авторизируйтесь.");
		if (isset($Arr_ParamAddNewUser))
			$_SESSION['Param_AddUser'] = $Arr_ParamAddNewUser;
	}

	$All_Message->add_Message("LogOn", "=КУКИСЫ===================================", 0 ,"Разработчик");

	If ($SystemValue->getUseCoockies() && isset($Arr_Sess['B_UseCookies'])) {
		If ($Arr_Sess['B_UseCookies']) {
			$_B_setCook = True;
			If (isset($_COOKIE['RCEngine'])) {
				If ($_COOKIE['RCEngine'] !== $Arr_Sess['S_IDSess']) {
					$_B_setCook = True;
				}
				$All_Message->add_Message("LogOn", "Полученный SID Cookies    = '" . $_COOKIE['RCEngine'] . "'", 0 ,"Разработчик");
			}
			Else {
				$_B_setCook = True;
				$All_Message->add_Message("LogOn", "Cookies не инициированы", 0 ,"Разработчик");
			}
			If ($_B_setCook) {
				setcookie('RCEngine', $Arr_Sess['S_IDSess'], time() + 60 * 60 * 24 * 3);
			}
		} Else {
			$All_Message->add_Message("LogOn", "Cookies не используются", 0 ,"Разработчик");
		}
	} Else {
		$All_Message->add_Message("LogOn", "Cookies не используются", 0 ,"Разработчик");
	}
	If (isset($ActivUser) && $ActivUser->getUseCookies() !== $Arr_Sess['B_UseCookies']) {
		$Arr_UserData = array(
				"ВидЗапроса" => "ИспользованиеКукис",
				"ИспользоватьКуки" => $Arr_Sess['B_UseCookies']
			);
		$Arr_Sess['B_UseCookies'] = $ActivUser->updateUserServices($MainConnect, $All_Message, $SystemValue, $Arr_UserData);
	}

	$All_Message->add_Message("LogOn", "Полученный SID сессии     = '" . $Arr_Sess['S_IDSess'] . "'", 0 ,"Разработчик");
	$All_Message->add_Message("LogOn", "Активный SID              = '" . session_id() . "'", 0 ,"Разработчик");
	$All_Message->add_Message("LogOn", "Обработка Cookies пройдена. Прошло времени: " . (microtime() - $TimeStartSys) . " мксек.", 0, "Разработчик");
	$All_Message->add_Message("LogOn", "=КУКИСЫ===================================", 0 ,"Разработчик");

	$All_Message->add_Message("Страница", "Страница:'" . $Str_Page . "'", 0 ,"Разработчик");

	If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
		include_once($SystemValue->getIncludeDir() . 'handlerAction.inc');
	Else
		include_once(BASE_PATH . Str_IncludeDir . DS . 'handlerAction.inc');
}
Else
	$All_Message->add_Message("LogOn", "При формировании страницы возникли неполадки. Перезапустите страницу или заходите позже. Мы обязательно исправим возникшие ошибки и недочеты", 3, "Пользователь");

If (strlen($Str_Description) > 160) {
	$Str_Description = substr($Str_Description, 0, 159);
}
$PrintPage->_Str_Description = $Str_Description;

If (isset($_thisSelectPage) && is_bool($_thisSelectPage)) $PrintPage->_SelectPage = $_thisSelectPage;
//$PrintPage->_Void_Data = $Void_Data;

unset ($Str_Description, $Str_AdresPage, $Str_Page, $Str_GetRole, $TimeStartSys, $Arr_Post, $Arr_Get, $Void_Data, $_thisSelectPage, $_Arr_Baners);

$PrintPage->Display($MainConnect, $All_Message, $SystemValue, $ActivUser);

If (isset($MainConnect) && $MainConnect->Boo_Use1CManager !== True && $MainConnect->ConnectDB)
	@$MainConnect->ConnectDB->close();

unset($MainConnect, $ActivUser, $All_Message, $PrintPage);

updateSessionVars($Arr_Sess);
If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
	include($SystemValue->getIncludeDir() . 'ClearSystemVars.inc');
Else
	include(BASE_PATH . Str_IncludeDir . DS . 'ClearSystemVars.inc');

unset($SystemValue);

session_write_close();

?>
