<?php
###############################################################################
###	Модуль с общими функциями
### Разработан с целью хранения общесистемных процедур и функций
###---------------------------------------------------------------------------
### Разработчик: А.Ю. Браун
### Дата разработки: 18.07.2017
###	Версия модуля: 1.00
###############################################################################
### Функции и процедуры модуля
###
### ----    в самом низу накиданы возможные наборы слова Select
###---------------------------------------------------------------------------
###	activate_session(String IDSession)			:Bool		- функция активации сессии и установки параметров сессии для текущего пользователя
###	updateSessionVar(Array IntraSessionVars)	:Bool		- обновление данных текущей сессии, касающихся данной системы, из данных внутреннего массива
###	deleteSessionVar()							:Bool		- удаление данных текущей сессии, касающихся данной системы
###	controlInputField(Object ErrorOfModul, Void Value, Bool Flag)
###												:Bool		- проверка значение на содержание запрещенных выражений, символов
###	controlInputField(Object ErrorOfModul, String Value, Bool Flag)
###												:Bool		- проверка значение на содержание SQL выражений
###	saveActiveMessage()							:Bool		- запись сообщения в переменную, для последующего вывода на страницу HTML
###	getNewGetForAdresStroka()					:String		- формирует подстроку GET для ссылки по текущему GET
###	Enter_Proc(String Value)								- выводит в тело HTML строку
###	Array_To_Tree(array $array, String $parent_id)
###												:Array 		- формирует иерархический массив из входящего линейного массива
###	GetAddresFromJSONArrayRF(array $ArrJSON)  	:Array		- формирует адрес из массива JSON международного формата для РФ
###
###############################################################################
### Описание процедур и функций
###---------------------------------------------------------------------------
###

###@@@@@@@@@@@@@@@@@@@@@
###	activate_session(String IDSession)
###		- функция активации сессии и установки параметров сессии для текущего пользователя
function activate_session($_S_SessionID = ""){###------- Входные параметры
### String IDSession		- ID сессии, которую неоходимо активировать
###------- Выходные параметры
###  Bool 	- признак удачной операции
###
	//if (isset($_SESSION['Str_IDUser']))
	//	$_SESSION['Str_IDUser'] = "";
	//	$_SESSION['Log_EnablePass'] = "";
	//	$_SESSION['Str_IPAdr'] = "";
	//	$_SESSION['Log_CookiesOn'] = 0;

	$_SESSION['Dat_DateEnter'] = date("Y-m-d");

	return True;}
###@@@@@@@@@@@@@@@@@@@@@

// Корректность ссылки (URL)
function check_url($url) {
	// удаление опасных сиволов (http://php.spb.ru/php/regexp.html)
	//$url = preg_replace("/[^x20-xFF]/", "", @strval($url));
	//echo $url;
	//if (!strstr($url, "://")) {
	//	$url = "http://".$url;
	//}

	// проверка ссылки на корретность (http://www.yukosh.ru/library/ideas/)

	if (preg_match("/^(http:\/\/|https:\/\/)(.*)(com|net|org|info|biz|spb.ru|msk.ru|com.ru|org.ru|net.ru|ru|su|us|bz|kz|ws|рф|pro)(.*)?$/i", $url)) {
		return $url;
	}

	return False;
}

// Существование файла в по указанному пути
function check_url_ForImage($url) {
	$ReturnValue = False;

	if (preg_match("/^(.*)(jpg|jpeg|svg|png|pcx|bmp|gif|ico|web|webp)(.*)?$/i", $url)) {
		$ReturnValue = True;
	}

	return $ReturnValue;
}

// Проверка на существование ссылки (URL)
function open_url($url) {

	$url_c = parse_url($url);

 	If (!empty($url_c['host']) && checkdnsrr($url_c['host'])) {
		// Ответ сервера
		If ($otvet = @get_headers($url)) {			//print_r($otvet);
			return substr($otvet[0], 9, 3);
		}
	}
	return False;
}
###@@@@@@@@@@@@@@@@@@@@@

###	array_search_str(String Value, array ArrayValue)
###		- поиск значения в массиве, мернет массив ключей вхождения значений
function array_search_str($search, $arr) {

	$result = array();
	Foreach ($arr As $key=>$val){		If (strpos($val, $search) !== False){
			$result[] = $key;
		}
	}
	return $result;
 }
###@@@@@@@@@@@@@@@@@@@@@

###	updateSessionVar($Arr_Sess)
###		- удаление данных текущей сессии, касающихся данной системы
function updateSessionVars($Arr_Sess) {
###------- Входные параметры
### Array $Arr_Sess		- массив временных данных сессии
###------- Выходные параметры
###  Bool 	- признак удачной операции
###

	if (isset($Arr_Sess['S_IDUser']))
		if (strlen(trim($Arr_Sess['S_IDUser'])) === 0) {
			if (isset($_SESSION['Str_IDUser']))
				unset($_SESSION['Str_IDUser']);
		}
		else
			$_SESSION['Str_IDUser'] = $Arr_Sess['S_IDUser'];
	else
		if (isset($_SESSION['Str_IDUser']))
			unset($_SESSION['Str_IDUser']);

	if (isset($Arr_Sess['B_UsePassword']))
		if ($Arr_Sess['B_UsePassword']) {
			if (isset($_SESSION['Log_EnablePass']))
				unset($_SESSION['Log_EnablePass']);
		}
		else
			$_SESSION['Log_EnablePass'] = $Arr_Sess['B_UsePassword'];
    else
		if (isset($_SESSION['Log_EnablePass']))
			unset($_SESSION['Log_EnablePass']);

	if (isset($Arr_Sess['D_OldDateIn']))
		if (strlen(trim($Arr_Sess['D_OldDateIn'])) === 0) {
			if (isset($_SESSION['Dat_DateEnter']))
				unset($_SESSION['Dat_DateEnter']);
		}
		else
			$_SESSION['Dat_DateEnter'] = $Arr_Sess['D_OldDateIn'];
	else
		if (isset($_SESSION['Dat_DateEnter']))
			unset($_SESSION['Dat_DateEnter']);

	if (isset($Arr_Sess['B_UseCookies']))
		if (!$Arr_Sess['B_UseCookies']) {
			if (isset($_SESSION['Log_CookiesOn']))
				unset($_SESSION['Log_CookiesOn']);
		}
		else
			$_SESSION['Log_CookiesOn'] = $Arr_Sess['B_UseCookies'];
	else
		if (isset($_SESSION['Log_CookiesOn']))
			unset($_SESSION['Log_CookiesOn']);

	if (isset($Arr_Sess['S_OldIPUser']))
		if (strlen(trim($Arr_Sess['S_OldIPUser'])) === 0) {
			if (isset($_SESSION['Str_IPAdr']))
				unset($_SESSION['Str_IPAdr']);
		}
		else
			$_SESSION['Str_IPAdr'] = $Arr_Sess['S_OldIPUser'];
	else
		if (isset($_SESSION['Str_IPAdr']))
			unset($_SESSION['Str_IPAdr']);

	if (isset($Arr_Sess['S_OldClient']))
		if (strlen(trim($Arr_Sess['S_OldClient'])) === 0) {
			if (isset($_SESSION['S_Client']))
				unset($_SESSION['S_Client']);
		}
		else
			$_SESSION['S_Client'] = $Arr_Sess['S_OldClient'];
	else
		if (isset($_SESSION['S_Client']))
			unset($_SESSION['S_Client']);

	return true;
}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	deleteSESSIONvar()
###		- удаление данных текущей сессии, касающихся данной системы
function deleteSessionVar() {
###------- Входные параметры
###
###------- Выходные параметры
###  Bool 	- признак удачной операции
###
	if (isset($_SESSION['Str_IDUser']))
		unset($_SESSION['Str_IDUser']);
	if (isset($_SESSION['Log_EnablePass']))
		unset($_SESSION['Log_EnablePass']);
	if (isset($_SESSION['Dat_DateEnter']))
		unset($_SESSION['Dat_DateEnter']);
	if (isset($_SESSION['Log_CookiesOn']))
		unset($_SESSION['Log_CookiesOn']);
	if (isset($_SESSION['Str_IPAdr']))
		unset($_SESSION['Str_IPAdr']);
	if (isset($_SESSION['S_Client']))
		unset($_SESSION['S_Client']);

	return true;
}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	clearSystemVars()
###		- удаление внутренних глобальных переменных системы
function clearSystemVars() {
###------- Входные параметры
###
###------- Выходные параметры
###  Bool 	- признак удачной операции
###
	if (isset($Arr_Sess))
		unset($Arr_Sess);
	if (isset($Arr_Get))
		unset($Arr_Get);
	if (isset($Arr_Post))
		unset($Arr_Post);

	return true;
}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	controlInputField(Object ErrorOfModul, Void Value, Bool Flag)
###		- проверка значение на содержание запрещенных выражений, символов
function controlInputField($All_Message, $Value, $ControlWord = False) {###------- Входные параметры
### Object ErrorOfModul		- Объект хранения сообщений по системе
### Void Value				- проверяемое значение
### Bool Flag				- проверять как True - слово, False - предложение
###------- Выходные параметры
###  Bool 	- признак удачной операции
###
	$ReturnValue = True;

	// Проверка типа проверяемого значения
	if (!is_string($Value))
		$ReturnValue = False;

	// если это проверка слова, выполнить дополнительную проверку на недоступные символы
	if ($ControlWord) {
		$ArraySimv = "*\/|`'[],.";
		$NewValue = strpbrk($Value, $ArraySimv);
		if (!is_bool($NewValue) && $NewValue !== $Value){
			$ReturnValue = False;
			$All_Message->add_Message("Контроль данных", "Слово содержит некорректные символы: '" . $Value . "' - '" . substr($NewValue, 0, 1) . "'", 0 ,"Администратор");		// Сообщение пользователю
		}
		else {
			$ArraySimv = '"';
			$NewValue = strpbrk($Value, $ArraySimv);
			if (!is_bool($NewValue) && $NewValue !== $Value){
				$ReturnValue = False;
				$All_Message->add_Message("Контроль данных", "Слово содержит некорректные символы: '" . $Value . "' - '" . substr($NewValue, 0, 1) . "'", 0 ,"Администратор");		// Сообщение пользователю
			}
		}
	}

###---------
	if (!$ReturnValue)
		$All_Message->add_Message("Контроль данных", "Слово содержит некорректные символы: '" . $Value . "' - '" . substr($NewValue, 0, 1) . "'", 0 ,"Администратор");		// Сообщение пользователю
###---------

	// выполнить проверку на содержание SQL выражений
	/*
	if ($ReturnValue && !NO_SQLValue($All_Message, $Value, $ControlWord))
		$ReturnValue = False;
    */
	return $ReturnValue;}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	controlInputField(Object ErrorOfModul, String Value, Bool Flag)
###		- проверка значение на содержание SQL выражений
function NO_SQLValue($All_Message, $Value, $ControlWord = False) {###------- Входные параметры
### Object ErrorOfModul		- Объект хранения сообщений по системе
### String Value			- проверяемое значение
### Bool Flag				- проверять как True - слово, False - предложение
###------- Выходные параметры
###  Bool 	- признак удачной операции
###
	$ReturnValue = True;

	$Value = html_entity_decode($Value, ENT_HTML5);					// декодируем строку из HTML формата
	if (strlen($Value) !== 0){                                          // проверим длину строки
		// требуется проверка на первый символ для функции
		if (substr($Value, 0, 1) !== '"' && substr($Value, 0, 1) !== '-' && substr($Value, 0, 1) !== "'") {
			// в зависимости от флага проверки слова/предложения
			if ($ControlWord) {				$CountWords = count(preg_split('/[^А-Яа-яЁёA-Za-z0-9_@$()]+/u', $Value));
				//print_r(preg_split('/[\s,]+/', $Value));
				// при необходимости проверки слова проверим на количество слов в строке, слов должно быть 1
				//if (str_word_count($Value) != 1)				if ($CountWords != 1)
					$ReturnValue = False;
			}
			else {				// при неоходимости проверки предложения, получим массив слов для дальнейшей обработки				//$ArrayWord = str_word_count($Value, 1);
				//$ArrayWord = explode(" ", $Value);
				$ArrayWord = preg_split('/[\s,]+/', $Value);			}
		}
		else
			$ReturnValue = False;
	}

	// если все предыдущие проверки удачны идем дальше, иначе смысла нет
	if ($ReturnValue) {		// массив SQL выражений
		$MassivSQLFunc = array("SELECT", "INSERT", "UPDATE", "DELETE", "DROP", "ALTER");

		// проверим значение проверяемого на содержание SQL выражений
		if ($ControlWord){
			// проверяю слово
			foreach ($MassivSQLFunc as $StrValue) {
				$NewValue = stristr($Value, $StrValue);
				if (!is_bool($NewValue) && strtolower($Value) == strtolower($StrValue)) {
					$ReturnValue = False;
					break;
				}
				unset($NewValue);
			}
		}
		else {			// проверяю предложение
			// без массива слов проверять не стоит
			if (isset($ArrayWord)) {
				// цикл по массиву проверяемых слов из предложения
				foreach($ArrayWord as $S_Word) {					// цикл по запрещенным словам					if (!$ReturnValue)
					break;
					foreach ($MassivSQLFunc as $StrValue) {
						if (strtolower($S_Word) == strtolower($StrValue)) {
							$ReturnValue = False;
							break;
						}

						$NewValue = $S_Word;
						$ValueBefore = stristr($NewValue, $StrValue, True);
						While (!is_bool($ValueBefore)){
							$LastSimv = substr($ValueBefore, (strlen($ValueBefore) - 1));
							if ($LastSimv === "'" || $LastSimv === '"' || $LastSimv === "." || $LastSimv === "," || $LastSimv === "!" || $LastSimv === "?" || $LastSimv === "~" || $LastSimv === "`" || $LastSimv === "/"){
								$ReturnValue = False;
								break;
							}
							$NewValue = substr($NewValue, strlen($ValueBefore . $StrValue));
							$ValueBefore = stristr($NewValue, $StrValue, True);
						}
					}
				}
				unset($ArrayWord);
				if (isset($S_Word))
					unset($S_Word);
				if (isset($ValueBefore))
					unset($ValueBefore);
				if (isset($LastSimv))
					unset($LastSimv);
			}
		}

		unset ($MassivSQLFunc);
		if (isset($StrValue))
			unset ($StrValue);
	}

	return $ReturnValue;
}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	saveActiveMessage()
###		- запись сообщения в переменную, для последующего вывода на страницу HTML
function saveActiveMessageFromErr($All_Message, $e, $ActivUser, $ModuleName = "Приложение") {###------- Входные параметры
### 			- строка для вывода
###------- Выходные параметры
###  Bool: признак удачного выполения функции
	$ReturnValue = True;

	if (is_string($ActivUser)) {
		if ($ActivUser === "Разработчик")
			$All_Message->add_Message($ModuleName, $e->getMessage(), 2, $ActivUser, $e->getCode(), $e->getFile(), $e->getLine());
		elseif ($ActivUser === "Администратор")
			$All_Message->add_Message($ModuleName, $e->getMessage(), 2, $ActivUser, $e->getCode());
		elseif ($ActivUser === "Модератор")
			$All_Message->add_Message($ModuleName, $e->getMessage(), 2, $ActivUser);
	}
	elseif (is_object($ActivUser)) {	}
	else
		$ReturnValue = False;

	return $ReturnValue;
}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	getNewGetForAdresStroka()
###		- формирует подстроку GET для ссылки по текущему GET
function getNewGetForAdresStroka($Arr_InsertParam = Null) {###------- Входные параметры
### ---
###------- Выходные параметры
### String - GET строка для ссылки
	$ReturnValue = "";

	$B_AddZnak = False;
	$i = 0;

	if (isset($_GET['roleconnect'])) {
		$ReturnValue .= (!$B_AddZnak ? "?" : "&") . "roleconnect=" . (int)$_GET['roleconnect'];
		$B_AddZnak = True;
	}

	//foreach ($_GET as $Param => $Value) {		//if ($Param !== 'RoleConnect')		//$ReturnValue .= (!$B_AddZnak ? "?" : "&") . $Param . "=". $Value;
		//$B_AddZnak = True;
	//}

	if (is_array($Arr_InsertParam) && count($Arr_InsertParam) <> 0) {
		for ($i = 0; $i < (count($Arr_InsertParam)); $i++) {
			//print_r(count($Arr_InsertParam));
			$ReturnValue .= (!$B_AddZnak ? "?" : "&") . $Arr_InsertParam[$i]['Параметр'] . "=" . $Arr_InsertParam[$i]['Значение'];
			$B_AddZnak = True;
		}
	}
	//print_r($ReturnValue);

	unset($B_AddZnak, $i);
	return $ReturnValue;}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	Enter_Proc(String Value)
###		- выводит в тело HTML строку
function Enter_Proc($Str) {
###------- Входные параметры
### String Value			- строка для вывода
###------- Выходные параметры
###
###
	echo $Str;}
###@@@@@@@@@@@@@@@@@@@@@

/*
		"SELECT", "select", "Select", "sElect", "seLect", "selEct", "seleCt", "selecT",
		"SElect", "SeLect",
*/

###@@@@@@@@@@@@@@@@@@@@@
###	Array_To_Tree(array $array, String $parent_id)
###		- формирует иерархический массив из входящего линейного массива
function Array_To_Tree(array $array, $parent_id = "") {
###------- Входные параметры
### Array array			- массив для преобразования
### String parent_id	- строка представления пустого элемента для поля Parent_Id
###------- Выходные параметры
### Array 	- иерархический массив
###

    $array = array_combine(array_column($array, 'ID'), array_values($array));

    foreach ($array as $k => &$v) {
        if (isset($array[$v['Parent_ID']])) {
            $array[$v['Parent_ID']]['Children'][$k] = &$v;
        }
        unset($v);
    }

    return array_filter($array, function($v) use ($parent_id) {
        return $v['Parent_ID'] == $parent_id;
    });
/*
Array ( [AAA0000001] => Array ( [ID] => AAA0000001 [Parent_ID] => [NameType] => Образование [Description] => Все об образовании [Children] => Array (
				[AAA0000003] => Array ( [ID] => AAA0000003 [Parent_ID] => AAA0000001 [NameType] => Детские сады [Description] => )
				[AAA0000004] => Array ( [ID] => AAA0000004 [Parent_ID] => AAA0000001 [NameType] => Школы [Description] => )
				)
		)
		[AAA0000002] => Array ( [ID] => AAA0000002 [Parent_ID] => [NameType] => Автомобили [Description] => )
		[AAA0000005] => Array ( [ID] => AAA0000005 [Parent_ID] => [NameType] => Спорт [Description] => Все для спорта [Children] => Array (
				[AAA0000007] => Array ( [ID] => AAA0000007 [Parent_ID] => AAA0000005 [NameType] => Стадионы [Description] => )
				[AAA0000008] => Array ( [ID] => AAA0000008 [Parent_ID] => AAA0000005 [NameType] => Авто/мото спорт [Description] => )
				)
		)
		[AAA0000006] => Array ( [ID] => AAA0000006 [Parent_ID] => [NameType] => Здоровье [Description] => Все о здоровье )
)
*/
}
###@@@@@@@@@@@@@@@@@@@@@

###@@@@@@@@@@@@@@@@@@@@@
###	GetAddresFromJSONArrayRF(array $ArrJSON)
###		- формирует адрес из массива JSON международного формата для РФ
function GetAddresFromJSONArrayRF(array $ArrJSON) {
###------- Входные параметры
### Array array			- формализованный массив адреса в JSON для преобразования
###------- Выходные параметры
### Array 	- массив преобразованный
###

	$ReturnValue = array();

	$_StrResult = "";
	If (is_array($ArrJSON) && isset($ArrJSON['street']) && strlen($ArrJSON['street']) > 0)
		$_StrResult = $_StrResult . $ArrJSON['street'] . " " . $ArrJSON['streetType'];
	If (is_array($ArrJSON) && isset($ArrJSON['houseNumber']) && strlen($ArrJSON['houseNumber']) > 0)
		$_StrResult = $_StrResult . (strlen($_StrResult) === 0 ? "" : ", ") . $ArrJSON['houseNumber'] . " " . $ArrJSON['houseType'];
	If (isset($ArrJSON['buildings']) && is_array($ArrJSON['buildings']) && count($ArrJSON['buildings']) > 0)
		$_StrResult = $_StrResult . (strlen($_StrResult) === 0 ? "" : ", ") . $ArrJSON['buildings'][0]['type'] . " " . $ArrJSON['buildings'][0]['number'];
	If (isset($ArrJSON['apartments']) && is_array($ArrJSON['apartments']) && count($ArrJSON['apartments']) > 0)
		$_StrResult = $_StrResult . (strlen($_StrResult) === 0 ? "" : ", ") . $ArrJSON['apartments'][0]['type'] . " " . $ArrJSON['apartments'][0]['number'];

	If (strlen($_StrResult) === 0 && isset($ArrJSON['Description']) && strlen($ArrJSON['Description']) !== 0)
		$_StrResult = $ArrJSON['Description'];
	$ReturnValue['Description'] = $_StrResult;

	$_StrFull = "";
	If (is_array($ArrJSON) && strlen($ArrJSON['ZIPcode']) > 0) {
		$_StrFull = $_StrFull . $ArrJSON['ZIPcode'];
		$ReturnValue['ZIPcode'] = $ArrJSON['ZIPcode'];
	}
	$ReturnValue['Country'] = array( "Name" => $ArrJSON['country'], "Code" => $ArrJSON['countryCode']);
	$_StrFull = $_StrFull . (strlen($_StrFull) === 0 ? "" : ", ") . $ArrJSON['Country'];

	$ReturnValue['City'] = "";
	If (is_array($ArrJSON) && isset($ArrJSON['area']) && strlen($ArrJSON['area']) > 0) {
		$_StrFull = $_StrFull . (strlen($_StrFull) === 0 ? "" : ", ") . $ArrJSON['area'] . (strlen($ArrJSON['areaType']) > 0 ? " " . $ArrJSON['areaType'] : "");
		$ReturnValue['City'] = $ArrJSON['area'] . (strlen($ArrJSON['areaType']) > 0 ? " " . $ArrJSON['areaType'] : "");
	};

	If (is_array($ArrJSON) && isset($ArrJSON['city']) && strlen($ArrJSON['city']) > 0) {
		$_StrFull = $_StrFull . (strlen($_StrFull) === 0 ? "" : ", ") . $ArrJSON['city'] . (strlen($ArrJSON['cityType']) > 0 ? " " . $ArrJSON['cityType'] : "");
		$ReturnValue['City'] = $ReturnValue['City'] . (strlen($ReturnValue['City']) > 0 ? ", " : "") .  $ArrJSON['city'] . (strlen($ArrJSON['cityType']) > 0 ? " " . $ArrJSON['cityType'] : "");
	};

	$ReturnValue['Full'] = $_StrFull . ", " . $_StrResult;
	$ReturnValue['Value'] = $ReturnValue['Full'];

	return $ReturnValue;

}
###@@@@@@@@@@@@@@@@@@@@@

?>
