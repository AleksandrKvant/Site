<?php
### Обработка системы
include(BASE_PATH . 'include' . DS . 'systems.inc');                                                         // Константы

#============ Переменные приложения
date_default_timezone_set('Europe/Moscow');
//setlocale(LC_ALL, 'ru_RU.utf8');
$TimeStartSys = microtime();

// Подключение функционала приложения
include(BASE_PATH . Str_IncludeDir . DS . 'include.inc');					// Подключение файла с функциями

// Собственные классы приложения
include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassErrMessage.inc');			// Подключение необходимых классов к приложению
include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassErrorOfModul.inc');		// Подключение необходимых классов к приложению
include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassConnections.inc');			// Подключение необходимых классов к приложению
include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassSystemConfig.inc');		// Подключение необходимых классов к приложению
include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassFullNamePeople.inc');		// Подключение необходимых классов к приложению
include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassUserConfig.inc');			// Подключение необходимых классов к приложению
//include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassImageLink.inc');			// Подключение необходимых классов к приложению
//include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassBanerType.inc');			// Подключение необходимых классов к приложению
//include_once(BASE_PATH . Str_IncludeDir . DS . 'ClassPageInetInfo.inc');			// Подключение необходимых классов к приложению

////////////////////////////////////////////////////
######      Конец описания объекта             #####
####################################################

// Дополнительные переменные
$All_Message = New ErrorOfModul();					// Объявление класса для хранинения сообщений
$B_DeleteSessionVar = False;

$Str_GetRole = "";
If (isset($_GET['roleconnect'])){
	Switch ((int)$_GET['roleconnect']) {		Case 100:			$Str_GetRole = "Разработчик";
			Break;
		Case 30:
			$Str_GetRole = "Админитратор";
			Break;
		Case 20:
			$Str_GetRole = "Модератор";
			Break;
		Default:
			$Str_GetRole = "";
	}
}

###---------
If ($Str_GetRole == NULL)
	$All_Message->add_Message("Приложение", "Переданный аргумент GET['roleconnect'] неопределен " , 0, "Разработчик");
Else
	$All_Message->add_Message("Приложение", "Переданный аргумент GET['roleconnect'] = " . $Str_GetRole, 0, "Разработчик");
$All_Message->add_Message("Приложение", "Версия PHP: " . phpversion(), 0, "Разработчик");
###---------

####################################################
#============ Формирование данных из глобальных источников: Сессия, Кукки, Клиент, Заголовки

#============ Формирование клиентских данных
$_SESSION['Log_CookiesOn'] = False;

If (isset($_COOKIE['RCEngine'])) {															// Если установленны куки на клиенте
	If (trim($_COOKIE['RCEngine']) !== '' && trim(session_id()) !== $_COOKIE['RCEngine']) {// Если данные сессии не совпадают с данными в Cookies пользователя
		$_SESSION = array();																// Обнулить сессию
		session_write_close();																// Закрыть сессию
		session_id($_COOKIE['RCEngine']);													// Считать идентификатор сессии
	}
	session_start();																			// Активировать сессию пользователя
	$_SESSION['Log_CookiesOn'] = True;
}
Else
	session_start();																			// Активировать сессию пользователя

/*
if ($_SESSION['Log_CookiesOn'] == True && trim($_COOKIE['RCEngine']) !== '') {				// Если установленны куки на клиенте
	setcookie('RCEngine', trim(session_id()), time() + 360000);								// Установить куки на клиенте
	//$TS_TimeOff = time() + 3;
	//while (time() <= $TS_TimeOff){}
	//unset($TS_TimeOff);
}
*/

//global $Arr_Get;
//global $Arr_Post;

#============ Формирование данных различных страниц
// определение типа страницы/имени блока
$Str_Page = "Стартовая";													// Объявление переменной наименования страницы
// ВНИМАНИЕ!!! определение страницы для сайта http://nemnogoobovsem.ru/
/*
If (preg_match('/index.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "index.php";
	$Str_Page = "Стартовая";									// Имя блока
}
Elseif (preg_match('/banerproperties.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "banerproperties.php";
	$Str_Page = "Свойства банера";								// Имя блока
}
Elseif (preg_match('/selectimageforlink.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "selectimageforlink.php";
	$Str_Page = "Выбор картинки банера";						// Имя блока
}
Elseif (preg_match('/restoreloginpage.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "restoreloginpage.php";
	$Str_Page = "Восстановление доступа";						// Имя блока
}
Elseif (preg_match('/loginpage.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "loginpage.php";
	$Str_Page = "Авторизация";									// Имя блока
}
Elseif (preg_match('/restoreinfo.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "restoreinfo.php";
	$Str_Page = "Информация о восстановлении";					// Имя блока
}
Elseif (preg_match('/restoreaccept.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "restoreaccept.php";
	$Str_Page = "Доступ восстановлен";							// Имя блока
}
Elseif (preg_match('/userpage.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "userpage.php";
	$Str_Page = "Личный кабинет";								// Имя блока
}
Elseif (preg_match('/myproperties.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "myproperties.php";
	$Str_Page = "Мои ссылки";									// Имя блока
}
Elseif (preg_match('/registeruser.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "registeruser.php";
	$Str_Page = "Регистрация";									// Имя блока
}
Elseif (preg_match('/newuserinfo.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "newuserinfo.php";
	$Str_Page = "Информация о регистрации";						// Имя блока
}
Elseif (preg_match('/getconfirmemail.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "getconfirmemail.php";
	$Str_Page = "Подтвердить адрес электронной почты";			// Имя блока
}
Elseif (preg_match('/confirmemail.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "confirmemail.php";
	$Str_Page = "Подтверждение адреса электронной почты";		// Имя блока
}
Elseif (preg_match('/preference.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "preference.php";
	$Str_Page = "Настройки системы";							// Имя блока
}
Elseif (preg_match('/quit.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "quit.php";
	$Str_Page = "Закрыть сеанс";								// Имя блока
}
Elseif (preg_match('/about.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "about.php";
	$Str_Page = "О проекте";									// Имя блока
}
Elseif (preg_match('/policysecurity.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "policysecurity.php";
	$Str_Page = "Политика конфиденциальности";					// Имя блока
}
Elseif (preg_match('/termsofuse.php/i', trim($_SERVER['REQUEST_URI']))){
	$Str_AdresPage = "termsofuse.php";
	$Str_Page = "Правила использования";						// Имя блока
}
*/

//echo trim($_SERVER['REQUEST_URI']);
//echo preg_match('/BanerProperties.php/i', trim($_SERVER['REQUEST_URI']));
//print_r($Str_Page);

#============ Подготовка массивов переданных данных для работы страниц
$Arr_Get = $_GET;
$Arr_Post = $_POST;
$Void_Data = array();																		// Объявление переменной данные для вывода на странице пользователю
$Arr_Sess['S_ServerRequestUri'] = trim($_SERVER['REQUEST_URI']);							// Сохранение серверного вызова

// Обработка переменных сессии и подключенных куки на клиенте
$Arr_Sess['S_IDSess'] = trim(session_id());													// Считать идентификатор Сессии пользователя

/*
if (isset($_COOKIE['RCEngine'])) {
	if ($_COOKIE['RCEngine'] !== $Arr_Sess['S_IDSess']) {									// Если установленны куки на клиенте
		setcookie('RCEngine', '');															// Удалить идентификатор сессии в куки
		setcookie('RCEngine', $Arr_Sess['S_IDSess'], time() + 360000);						// Записать новое значение сессии в куки
	}
	$Arr_Sess['B_UseCookies'] = True;														// Установить признак использования куки
}
else {
	$Arr_Sess['B_UseCookies'] = False;														// Установить признак использования куки
}
*/

If (isset($_SESSION['Str_IDUser']))
	$Arr_Sess['S_IDUser'] 		= $_SESSION['Str_IDUser'];
Else
	$Arr_Sess['S_IDUser'] 		= "";

If (isset($_SESSION['Log_CookiesOn']))
	$Arr_Sess['B_UseCookies'] 	= $_SESSION['Log_CookiesOn'];
Else
	$Arr_Sess['B_UseCookies'] 	= False;

If (isset($_SESSION['Log_EnablePass']))
	$Arr_Sess['B_UsePassword'] 	= $_SESSION['Log_EnablePass'];
Else
	$Arr_Sess['B_UsePassword'] 	= True;

If (isset($_SESSION['Dat_DateEnter']))
	$Arr_Sess['D_OldDateIn'] 	= $_SESSION['Dat_DateEnter'];
Else
	$Arr_Sess['D_OldDateIn'] 	= date("Y-m-d");

If (isset($_SESSION['Str_IPAdr']))
	$Arr_Sess['S_OldIPUser'] 	= $_SESSION['Str_IPAdr'];
Else
	$Arr_Sess['S_OldIPUser'] 	= "";

If (isset($_SESSION['S_Client']))
	$Arr_Sess['S_OldClient'] 	= $_SESSION['S_Client'];
Else
	$Arr_Sess['S_OldClient'] 	= "";

$Arr_Sess['S_ThisIPUser'] 		= $_SERVER['REMOTE_ADDR'];
If (isset($_SERVER['HTTP_REFERER']))
	$Arr_Sess['S_Refferer'] 	= $_SERVER['HTTP_REFERER'];
Else
	$Arr_Sess['S_Refferer'] 	= "";

$Arr_Sess['S_Client'] 			= $_SERVER['HTTP_USER_AGENT'];

If (isset($_SERVER['HTTP_X_FORWARDED_FOR']))
	$Arr_Sess['S_Forwarded'] 	= $_SERVER['HTTP_X_FORWARDED_FOR'];
Else
	$Arr_Sess['S_Forwarded'] 	= "";

If (isset($_SESSION['Param_AddUser']))
	$Arr_ParamAddNewUser 	= $_SESSION['Param_AddUser'];

// ВНИМАНИЕ!!! Для сайта http://nemnogoobovsem.ru/
//Очистка свойств сессии от лишних данных Свойства банера
/*
If ($Str_Page !== "Выбор картинки банера" && $Str_Page !== "Свойства банера") {	If (isset($_SESSION['SelBanerPID']))
		unset($_SESSION['SelBanerPID']);
	If (isset($_SESSION['Arr_BanerProp']))
		unset($_SESSION['Arr_BanerProp']);
}
*/
#============ Подключение и считывание данных из БД
$MainConnect = New Connections();
$MainConnect->Str_DBName = Str_DBName;
$MainConnect->Str_DBType = Str_DBType;
$MainConnect->Str_HostName = Str_HostName;
$MainConnect->Str_HostIP = Str_HostIP;
$MainConnect->Int_Port = Int_Port;
$MainConnect->Str_Socket = Str_Socket;
$MainConnect->Str_AccountName = Str_AccountName;
$MainConnect->Str_AccountPass = Str_AccountPass;
$MainConnect->Boo_Use1CManager = Boo_Use1CManager;
$MainConnect->Boo_HTTPServices = Boo_HTTPServices;
$MainConnect->Boo_UseProtectConnect = Boo_UseProtectConnect;

If ($MainConnect->Boo_Use1CManager == True) {
	$All_Message->Add_Message("Приложение", "Начало обработки динамических данных", 0, "Разработчик");
	$SystemValue = New SystemConfig($MainConnect, $All_Message, $Arr_Sess);

} Else {
	// Попытка установки соединения с БД
	If ($MainConnect->setConnection($All_Message)) {

		$All_Message->Add_Message("Приложение", "Начало обработки динамических данных", 0, "Разработчик");
		$SystemValue = New SystemConfig($MainConnect, $All_Message, $Arr_Sess);

	}
}

If (isset($Arr_Get['linkresurs'])){
	If (is_object($SystemValue)) {
	    $Arr_Params = array();
	    $Arr_Params["LinkResurs"] = $Arr_Get['linkresurs'];
	    If (isset($Arr_Get['selbaner']) && $Arr_Get['selbaner'] !== "")
	    	$Arr_Params["SelBaner"] = $Arr_Get['selbaner'];
	    $SystemValue->RedirectInLinkAddr($MainConnect, $All_Message, $Arr_Params);
		header("Location: " . $Arr_Get['linkresurs'], true);					// перенаправление по ссылке
	}
}

// ВНИМАНИЕ!!! Переработанный механизм определения страницы
If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True) {
	$Str_Page = $SystemValue->S_ActivePage;
/*
	If (count($SystemValue->getMenuPortal()) > 0) {
		ForEach ($SystemValue->getMenuPortal() as $Value) {
			If (preg_match('/' . $Value["ИмяФайлаЗапуска"] . '/i', trim($_SERVER['REQUEST_URI']))){
				$Str_AdresPage = $Value["ИмяФайлаЗапуска"];
				$Str_Page = $Value["Наименование"];								// Имя блока
				$Str_PageHeading = $Value["СтраницаНаименование"];				// Имя блока
				break;
			}
		}
	}
*/
}

If (is_object($SystemValue) && $SystemValue->getUseAccount()) {
	$All_Message->Add_Message("Приложение", "Используется логирование пользователей", 0, "Разработчик");
	Try {
		If (strlen($Arr_Sess['S_IDUser']) > 0 && !$Arr_Sess['B_UsePassword']) { 			// Если инициализированна переменная в Сессии ID пользователя
			$All_Message->Add_Message("Приложение", "Считывание данных пользователя по сохранкенным параметрам", 0, "Разработчик");
			$ActivUser = New UserConfig();
			If (!$ActivUser->readUserFromBaseByID($MainConnect, $SystemValue, $All_Message, $Arr_Sess)) {
				Throw New Exception("!!!Неверно сформированные данные в сессии: 'S_IDUser', 'Log_EnablePass'!!!"); 	// Вызвать исключение
			}
		}

		If (!isset($ActivUser)) {
			$All_Message->Add_Message("Приложение", "Считывание данных пользователя по введенным данным на странице", 0, "Разработчик");
			If (!isset($Arr_Post['But_Cancel'])) {
				If (isset($Arr_Post['sys_username']) && isset($Arr_Post['sys_password'])) {
//					echo $Arr_Post['sys_username'];
//					echo $Arr_Post['sys_password'];
					If (controlInputField($All_Message, $Arr_Post['sys_username'], True)) {
						$All_Message->Add_Message("Приложение", "Проверка введенных данных пройдена", 0, "Разработчик");
						$ActivUser =  New UserConfig();
						If (!$ActivUser->readUserFromBase($MainConnect, $SystemValue, $All_Message, $Arr_Post['sys_username'], $Arr_Post['sys_password'], $Arr_Sess)) {
							unset($ActivUser);
						}
					}
					Else {
						$Str_Error = htmlspecialchars($Arr_Post['sys_username']);
						Throw New Exception("!!!В введенных данных пользователя содержатся некорректые фразы: Arr_Post['sys_username'] = '" . $Str_Error . "'!!!"); // Вызвать исключение
					}
				}
			}
		}
	}
	Catch (Exception $e) {							// Обработчик ошибки обработки введенных данных
		$Arr_Sess['S_IDUser'] = "";
		$Arr_Sess['B_UsePassword'] 	= 1;

		If (isset($Arr_Post['sys_username'])) {
			$Arr_Post['sys_username'] = "";
			$_POST['sys_username'] = "";
		}
		If (isset($Arr_Post['sys_password'])) {
			$Arr_Post['sys_password'] = "";
			$_POST['sys_password'] = "";
		}

		If (isset($ActivUser))
			unset($ActivUser);
		updateSessionVars($Arr_Sess);
		deleteSessionVar();

		If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
			$Fil_LogErr = $SystemValue->getLogFile();													// Путь и наименование файла логов
		Else
			$Fil_LogErr = Str_PathFileLogs."log.CGISQLerr";												// Путь и наименование файла логов

		Try {
			$Handler = @fopen($Fil_LogErr, "ab");														// Открыть файл для записи в конец файла, если файла нет то создать
			If ($Handler) {																				// Если файл открыт
				If (@flock($Handler, LOCK_EX)) {
					$Str_IP = $Arr_Sess['S_ThisIPUser'];
					If (($Arr_Sess['S_Forwarded'] != NULL) && ($Arr_Sess['S_Forwarded'] != $Arr_Sess['S_ThisIPUser']))
						$Str_IP .= "/". $Arr_Sess['S_Forwarded'];						// Если прокси и адрес клиента не совпадают и прокси существует то добавить к ip адресу клиента прокси адрес

					Try {
						$NkB = @fwrite($Handler, date("d.m.y - H:i - ") . $e->getMessage() .
							"! IP: " . $Str_IP . ".\n");													// Записать в файл ошибки с указанием даты записи, времени и ip адреса клиента

						saveActiveMessageFromErr($All_Message, $e, $Str_GetRole, Str_DBName);				// Добавить сообщение в массив сообщений

						If ($NkB == 0)																		// Если запись не удалась
							throw new FWException($e->getMessage() . ". Ошибка записи в файл!");			// Вызвать обработчик ошибки записи в файл
				    }
				    Catch (FWException $FWe){																// Обработчик ошибки записи в файл
						$All_Message->Log_GlobalError = True;
						saveActiveMessageFromErr($All_Message, $FWe, $Str_GetRole, Str_DBName);				// Добавить сообщение в массив сообщений
				    }
			    	@flock($Handler, LOCK_UN);
		    	}
		    	@fclose($Handler);																		// Закрыть файл
		    	unset($Str_IP, $NkB);																	// Освободить память переменных
		   	}
		   	Else
				Throw New FOException($Str_ErrorThis . ". Ошибка открытия файла!");						// Вызвать обработчик ошибки открытия файла
		}
		Catch (FOException $FOe) {																		// Обработчик ошибки открытия файла
			$All_Message->Log_GlobalError = True;
			saveActiveMessageFromErr($All_Message, $FOe, $Str_GetRole, Str_DBName);						// Добавить сообщение в массив сообщений
		}
		unset($Str_ErrorThis, $Fil_LogErr);																// Освободить память переменных
		If (isset($Handler))
			unset($Handler);
	}
}

If (isset($SystemValue) && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
	include($SystemValue->getIncludeDir() . 'handlerPages.inc');
Else
	include(BASE_PATH . 'Include' . DS . 'handlerPages.inc');                                                         // Константы

?>