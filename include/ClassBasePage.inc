<?php
	####################################################
	########    Объект "Базвая Страница сайта"    ######
	####################################################
	class BasePage{
	### Наименование - BasePage
	###		Объект для хранения и обработки объекта автоматизации "Базовая Страница сайта"
	###			необходим для создания однотипных страниц сайта
    ###-------------------------------------------------
    ###  Требуются объекты для работы
    ### ErrorOfModul		// Объект "Сообщения системы"
    ### SystemConfig		// Объект "Конфигурация"
    ### UserConfig			// Объект "Пользователь"
	////////////////////////////////////////////////////
	################    Свойства    ####################
	////////////////////////////////////////////////////
	###////// Открытые
	### _S_Content 				контент страницы
	###------------------------------------------------
	###////// Защищенные
	### _Str_PageIdent 			Поный идентификатор страницы
	###------------------------------------------------
	###////// Внутренние
	###------------------------------------------------
	###////// Требующие реализации
	###
	////////////////////////////////////////////////////
	###########   Методы класса   ######################
	////////////////////////////////////////////////////
	###////// Открытые
	###
	### setContentProperty(Array Value)			:Bool		- Установка значений свойства класса (_Arr_ContentType)
	### getContentProperty()					:Array		- Считывание значений свойства класса (_Arr_ContentType)
				// Array {
				//			ВидКонтента:					// Тип контента
				//					Новости
				//					Статьи
				//					ТоварыИУслуги
				//					Проекты
				//					БанерыПользователей
				//					Реклама
				//					Партнеры
				//			КоличествоЭлементов				// количество элементов
				//			НеограниченноеКоличество		// признак неограниченного количества
				//			КоличествоЭлементовНаСтранице	// выводимое количество элементов на страницу
				//			СтраницаНаименование			// Имя страницы реестра контента
				//			СтраницаАдреснаяСтрока			// Адрес страницы, имя начального файла
				//			СтраницаПолнаяАдреснаяСтрока	// Полная адресная строка до страницы реестра контента
				//		}
	### getTextContentProperty()				:String		- Считывание значений свойства класса (_Str_TextContent)
	### readContentTypeProperty(Object Connection, Object ErrorOfModul, object SystemConfig)
	### 										:Bool		- Инициализация заполнения значений свойства класса (_Arr_ContentType)
	////////////////////////////////////////////////////
	###////// Наследуемые
	###
	////////////////////////////////////////////////////
	###////// Внутренние
	###
	### getTypesContentsPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue)
	### 										:Bool		- Читает информацию о типах контента страницы из базы методом 1С (WEB запрос)
	### getListOfDocumentsContentsPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue)
	### 										:Bool		- Читает список документов контента страницы из базы методом 1С (WEB запрос)
	### getDocumentContentPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue, Sring Type, String PID)
	###											:Bool		- Читает детализацию контента страницы из базы методом 1С (HTTP запрос)
	### getTextContentPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue)
	### 										:Bool		- Читает данные контента страницы из базы методом 1С (HTTP запрос)
	////////////////////////////////////////////////////
	##########       Свойства класса       #############
	////////////////////////////////////////////////////
	### Открытые
		public $_Str_AdresPage;			// Полный идентификатор страницы
	###
	### Наследуемые
		protected $_Str_PageIdent;			// Полный идентификатор страницы
		protected $_Str_Description;		// Описание в метатеге Description
		protected $_Str_Tittle;				// Описание в метатеге Tittle
		protected $_Str_GETRole;			// Параметр "Роль" из строки GET
		protected $_Bool_ReadOnly;			// Признак для страницы - только чтение
		protected $_Time_StartSys;			// Дата начала формирования страницы
		protected $_Arr_Post;				// POST параметры
		protected $_Arr_Get;				// GET параметры
		protected $_SelectPage;				// признак страницы отбора
		protected $_Void_Data;				// различные данные для вывода на экран
	###
	### Внутренние
		private $_Arr_ContentType;			// Массив структуры типов контента страницы
				// Array {				//			ВидКонтента:					// Тип контента
				//					Новости
				//					Статьи
				//					ТоварыИУслуги
				//					Проекты
				//					БанерыПользователей
				//					Реклама
				//					Партнеры
				//			КоличествоЭлементов				// количество элементов
				//			НеограниченноеКоличество		// признак неограниченного количества
				//			КоличествоЭлементовНаСтранице	// выводимое количество элементов на страницу				//			СтраницаНаименование			// Имя страницы реестра контента
				//			СтраницаАдреснаяСтрока			// Адрес страницы, имя начального файла
				//			СтраницаПолнаяАдреснаяСтрока	// Полная адресная строка до страницы реестра контента
				//		}
		private $_Str_TextContent;			// Teкст контента страницы
	###

	////////////////////////////////////////////////////
	##########        Методы класса        #############
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	###////// Открытые
 	////////////////////////////////////////////////////

	###@@@@@@@@@@@@@@@@@@@@@
	###  Конструктор класса
	### __construct()
	### 	Создание объекта класса
		function __construct($NamePage = "Стартовая"){
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Object - объект типа BasePage
	###
			$this->_Str_AdresPage = "";
			$this->_Str_PageIdent = $NamePage;
			$this->_Bool_ReadOnly = True;
			$this->_Str_Description = "";
			$this->_Str_Tittle = "";
			$this->_Str_GETRole = "";
			$this->_Arr_Post = array();
			$this->_Arr_Get = array();
			$this->_SelectPage = False;
			$this->_Void_Data = Null;
			$this->_Arr_ContentType = array();
			$this->_Str_TextContent = "";
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Установка значений класса
	### __set(String Name_Var, Void _Value_Var)
	### 	установка защищенных и внутренних знчений свойств класса
		function __set($_Name_Var, $_Value_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###  Void _Value_Var			- Значение переменной
	###------- Выходные параметры
	###
			$this->$_Name_Var = $_Value_Var;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Считывание значений свойств класса
	### __get(String Name_Var)
	### 	Считывание значений свойств класса
		function __get($_Name_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###------- Выходные параметры
	###  Void _Value_Var			- Значение переменной
	###
			//$ReturnValue = false;
			$ReturnValue = $this->$_Name_Var;

			return $ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Установка значений свойства класса (_Arr_ContentType)
	### setContentProperty(Array Value)
	### 	Установка значений свойства класса (_Arr_ContentType)
		function setContentProperty($Value) {
	###------- Входные параметры
	###  Array Value			- массив типорв банеров
	###------- Выходные параметры
	###  bool					- признак удачного выполнения операции
	###
			$ReturnValue = True;
			If (is_array($Value))
				$this->_Arr_ContentType = $Value;
			Else
				$ReturnValue = False;

			return $ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Инициализация заполнения значений свойства класса (_Arr_ContentType)
	### readContentTypeProperty(Connections Connection, ErrorOfModul ErrorOfModul, SystemConfig SystemConfig)
	### 	Инициализация заполнения значений свойства класса (_Arr_ContentType)
		function readContentTypeProperty(&$MainConnect, $All_Message, &$SystemValue = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###------- Выходные параметры
	###  Bool			- признак удачного выполнения операции
	###
			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {
				$_ReturnValue = $this->getTypesContentsPageFromBase1CMethod($MainConnect, $All_Message, $SystemValue);
			} Else {				$_ReturnValue = False;
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Считывание значений свойства класса (_Arr_ContentType)
	### getContentProperty()
	### 	Считывание значений свойства класса (_Arr_ContentType)
		function getContentProperty() {
	###------- Входные параметры
	###  -
	###------- Выходные параметры
	###  Array			- массив типорв банеров
	###

			return $this->_Arr_ContentType;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Считывание значений свойства класса (_Str_TextContent)
	### getTextContentProperty()
	### 	Считывание значений свойства класса (_Str_TextContent)
		function getTextContentProperty() {
	###------- Входные параметры
	###  -
	###------- Выходные параметры
	###  String				- значение свойства _Str_TextContent
	###

			return $this->_Str_TextContent;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Инициализация чтения детальной информации контента страницы
	### readDetailContentProperty(Connections Connection, ErrorOfModul ErrorOfModul, SystemConfig SystemConfig, Sring Type, String PID)
	### 	Инициализация чтения детальной информации контента страницы
		function readDetailContentProperty(&$MainConnect, $All_Message, &$SystemValue, $TypeContent, $PIDContent) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  Sring Type							- Тип данных контента
	###  String PID							- Идентификатор данных контента
	###------- Выходные параметры
	###  Bool			- признак удачного выполнения операции
	###
			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {
				$_ReturnValue = $this->getDocumentContentPageFromBase1CMethod($MainConnect, $All_Message, $SystemValue, $TypeContent, $PIDContent);
			} Else {
				$_ReturnValue = False;
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать страницы
	### display(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать страницы веб сайта
		function display(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			$this->PrintBegin();
			$this->PrintTittle($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintKeyWords($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintStyles($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintScripts($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintHeader($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintContent($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintFooter($MainConnect, $All_Message, $SystemValue, $ActivUser);
			$this->PrintEnd();
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать начала страницы
	### PrintBegin()
	### 	Печать начала страницы веб сайта
		function PrintBegin() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html><head>
<?php
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать заголовка страницы
	### PrintTitle(EConnections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать заголовка страницы веб сайта
		function PrintTittle(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			$Str_HTMLStroka = ($this->_Str_PageIdent === "Стартовая" ? "": $this->_Str_PageIdent . ". ");
			if (isset($SystemValue) && $SystemValue->getUseValueBD() === True)
				$Str_HTMLStroka .=  $SystemValue->getSystemName();
			else
				$Str_HTMLStroka .= Str_SystemName;

?>
	<title><?php echo $Str_HTMLStroka ?></title>
	<meta HTTP-EQUIV="Content-Type" Content="text/html; charset=UTF-8">
	<meta name="viewport" content="width=device-width; height=device-height;">
<?php
			If (strlen($this->_Str_Description) > 0) {
?>
	<meta name="description" content="<?php echo $this->_Str_Description; ?>">
<?php
			}
?>
	<link rel="icon" href="favicon.svg" type="image/svg+xml">
	<link rel="shortcut icon" href="favicon.svg" type="image/svg+xml">
	<!<link rel="icon" href="favicon.ico" type="image/x-icon">
	<!<link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
<?php
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать ключевых слов страницы
	### PrintKeyWords(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать ключевых слов страницы веб сайта
		function PrintKeyWords(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			echo "<meta name=\"keywords\" content=\"" . $SystemValue->S_FindContent . "\" />\n";
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать стилей страницы
	### PrintStyles(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать подключаемых стилей страницы веб сайта
		function PrintStyles(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
				echo "<link href=\"./" . $SystemValue->getStylesDir() . "style.css\" type=text/css rel=stylesheet>\n";
			Else
				echo "<link href=\"./" . Str_StylesDir . DS . "style.css\" type=text/css rel=stylesheet>\n";
			If ($this->_Str_PageIdent === "Настройки системы") {
				If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
					echo "<link href=\"./" . $SystemValue->getStylesDir() . "styleConfig.css\" type=text/css rel=stylesheet>\n";
				Else
					echo "<link href=\"./" . Str_StylesDir . DS . "styleConfig.css\" type=text/css rel=stylesheet>\n";
			}
			//echo "<meta HTTP-EQUIV=\"Content-Type\" Content=\"text/html; charset=UTF-8\">";
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать скриптов страницы
	### PrintScripts(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать блока подключаемых скриптов страницы веб сайта
		function PrintScripts(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
//			echo "<script type=\"text/javascript\" SRC=\"". Put_File ."/scripts/image-button.js\"></script>";
//			echo "<script type=\"text/javascript\" SRC=\"". Put_File ."/scripts/script_town.js\"></script>";
//			echo "<script type=\"text/javascript\" SRC=\"". Put_File ."/scripts/swim.js\"></script>";
//			if ($Polsov)
//				echo "<script type=\"text/javascript\" SRC=\"". Put_File ."/scripts/edit_elem.js\"></script>";
// <script type="text/javascript" src="./Scripts/extent-page.js"></script>
			If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
				echo "<script type=\"text/javascript\" src=\"./" . $SystemValue->getScriptDir() . "jquery-3.3.1.js\"></script>\n";
			Else
				echo "<script type=\"text/javascript\" src=\"./" . Str_ScriptDir . DS . "jquery-3.3.1.js\"></script>\n";

			If ($SystemValue->getUseCoockies()) {
				If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
					echo "<script type=\"text/javascript\" src=\"./" . $SystemValue->getScriptDir() . "jquery.cookie.js\"></script>\n";
				Else
					echo "<script type=\"text/javascript\" src=\"./" . Str_ScriptDir . DS . "jquery.cookie.js\"></script>\n";
			}
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать пользовательского заголовка страницы
	### PrintHeader(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать пользовательского заголовка страницы веб сайта
		function PrintHeader(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
?>
</head><body>
<?php
			if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
				include($SystemValue->getIncludeDir() . 'PageArea/AreaBeginBody.inc');		// печать области начала тела
			else
				include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/AreaBeginBody.inc');					// печать области начала тела
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать контента страницы
	### PrintContent(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать контента страницы веб сайта
		function PrintContent(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			// формирование контента страницы
			If ($All_Message->Log_GlobalError) {
				echo "<div style=\"width: 100%; height: 100%; text-align: center; display: grid; align-content: center;\"><br/>\n";
				echo "<h3>На сайте(сервере) ведутся технические работы. Заходите позже</h3> <br/> <p>Приносим свои извинения</p>";
				echo "<br/>\n</div>";
			}

			//ВНИМАНИЕ!!! Статичная разраюотка для сайта http://nemnogoobovsem.ru/
			/*
			Elseif ($this->_Str_PageIdent === "Авторизация") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentLoginPage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentLoginPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Информация о восстановлении") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentRestoreInfo.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentRestoreInfo.inc');
			}
			Elseif ($this->_Str_PageIdent === "Доступ восстановлен") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentRestoreAccept.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentRestoreAccept.inc');
			}
			Elseif ($this->_Str_PageIdent === "Настройки системы") {
//				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
//					include($SystemValue->getIncludeDir() . 'PageArea\\ContentReferencePageTable.inc');
//				else
//					include(Str_IncludeDir . 'PageArea\\ContentReferencePageTable.inc');
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentReferencePage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentReferencePage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Регистрация") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentRegisterPage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentRegisterPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Свойства банера") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentBanerPropertiesPage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentBanerPropertiesPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Выбор картинки банера") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentSelectImagePage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentSelectImagePage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Личный кабинет") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentUserPage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentUserPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Мои ссылки") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentMyPropertiesPage.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentMyPropertiesPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Информация о регистрации") {
				If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentNewUserInfoPage.inc');
				Else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentNewUserInfoPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Подтвердить адрес электронной почты") {
				If (isset($Sy	stemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentSendConfirmEMail.inc');
				Else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentSendConfirmEMail.inc');
			}
			Elseif ($this->_Str_PageIdent === "Подтверждение адреса электронной почты") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentConfirmEMail.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentConfirmEMail.inc');
			}
			Elseif ($this->_Str_PageIdent === "Восстановление доступа") {
				if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentRestoreLoginInfo.inc');
				else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentRestoreLoginInfo.inc');
			}
			Elseif ($this->_Str_PageIdent === "О проекте") {
				If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentAboutPage.inc');
				Else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentAboutPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Политика конфиденциальности") {
				If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentPolicySecurityPage.inc');
				Else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentPolicySecurityPage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Правила использования") {
				If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentTermsOfUsePage.inc');
				Else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentTermsOfUsePage.inc');
			}
			Elseif ($this->_Str_PageIdent === "Стартовая") {
				If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
					include($SystemValue->getIncludeDir() . 'PageArea/ContentMainPage.inc');
				Else
					include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/ContentMainPage.inc');
			}
            */

			If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True) {
				If (count($SystemValue->getMenuPortal()) > 0) {
					ForEach ($SystemValue->getArrayPagesPortal() As $Value) {
						//print_r($Value);
						//If ($Str_Page === $Value["НаименованиеКраткое"]){
						If ($this->_Str_PageIdent === $Value["НаименованиеКраткое"]){							//echo $Value["НаименованиеКраткое"] . " - " . $SystemValue->getIncludeDir() . 'PageArea/' . $Value["ИмяФайлаОбработчика"];							include($SystemValue->getIncludeDir() . 'PageArea/' . $Value["ИмяФайлаОбработчика"]);
							break;
						}
					}
				}
			}

			If ($this->_Str_GETRole === "Разработчик" || (isset($ActivUser) && $ActivUser->isDeveloper())) {
				$this->PrintDeveloper($MainConnect, $All_Message, $SystemValue, $ActivUser);
			}
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать подвала страницы
	### PrintFooter(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать подвала страницы веб сайта
		function PrintFooter(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			// формирование подвала страницы
			if (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
				include($SystemValue->getIncludeDir() . 'PageArea/AreaEndBody.inc');		// печать области завершения тела
			else
				include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/AreaEndBody.inc');						// печать области завершения тела
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать пользовательского заголовка страницы
	### PrintHeader(Connections Connection, ErrorOfModul All_Message[, SystemConfig SystemValue[, UserConfig ActivUser]])
	### 	Печать пользовательского заголовка страницы веб сайта
		function PrintDeveloper(&$MainConnect, $All_Message, &$SystemValue = Null, &$ActivUser = Null) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  UserConfig ActivUser				- Объект пользователь приложения
	###
	###------- Выходные параметры
	###
			// информационная часть страницы для разработчика
###---------
				$All_Message->add_Message("Приложение", "Формирование данных закончено. Прошло времени: " . (microtime() - $this->_Time_StartSys) . " мксек.", 0, "Разработчик");
###---------
			// формирование данных для разработчика
			If (isset($SystemValue) && $SystemValue->getUseValueBD() == True)
				include($SystemValue->getIncludeDir() . 'PageArea/AreaDevelopment.inc');	// печать области завершения тела
			Else
				include(BASE_PATH . Str_IncludeDir . DS . 'PageArea/AreaDevelopment.inc');					// печать области разработчика
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###  Печать заключения страницы
	### PrintEnd()
	### 	Печать заключения страницы веб сайта
		function PrintEnd() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###
?>
</body></html>
<?php
		}
	###@@@@@@@@@@@@@@@@@@@@@

	////////////////////////////////////////////////////
	###////// Внутренние
	////////////////////////////////////////////////////

	###@@@@@@@@@@@@@@@@@@@@@
	###  Считывание информации о типах контента страницы
	### getTypesContentsPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue)
	### 	Читает информацию о типах контента страницы из базы методом 1С (WEB запрос)
		private function getTypesContentsPageFromBase1CMethod(&$MainConnect, $All_Message, &$SystemValue) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###------- Выходные параметры
	###

			$_ReturnValue = True;

			$Str_Object = "Объект 'Страница портала'";
			$All_Message->Add_Message($Str_Object, "Начало получения данных заголовков контента страницы", 0, "Разработчик");

			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/ws/PortalMaintenance.1cws?wsdl';

			$ValueConnection = $MainConnect->setConnection($All_Message);

			$Result = NULL;
			If ($ValueConnection) {
				Try {
					$Arr_Params = Array(
						"НаименованиеСтраницы" => $this->_Str_PageIdent
					);

					$JSONData = json_encode($Arr_Params, JSON_UNESCAPED_UNICODE);
					$ParamMethod = array(
							"CodePortal" => Str_PortalIdent,
							"Parameters" => $JSONData
						);

					$HTTPConnection = $MainConnect->ConnectDB;
					$Result = $HTTPConnection->GetTypePageContentInfo($ParamMethod)->return;
				} Catch(Exception $e) {
					$All_Message->Add_Message($Str_Object, "Ошибка обращения к методу 'GetTypePageContentInfo()' WEB сервиса '" . $MainConnect->Str_HTTPWSAdress . "'. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
					$MainConnect->insertLogMessage($All_Message ,$e->getMessage());
					$_ReturnValue = False;
					$Result = NULL;
				}
			}
			$MainConnect->Str_HTTPWSAdress = "";

			If ($Result !== NULL && is_object($Result)) {
				If (isset($Result->Error) && $Result->Error == False) {
					$ArrResult = json_decode($Result->Result, True);
					If (is_array($ArrResult)) {		 				$this->_Arr_ContentType = $ArrResult;
					} Else {
						$All_Message->Add_Message($Str_Object, "Ошибка получения данных заголовков контента страницы. Некорректные данные ответа", 0, "Разработчик");
					}
					unset($ArrResult);
				} Else {
					$All_Message->Log_GlobalError = True;
					If (isset($Result->ErrorMessage))
						$All_Message->Add_Message($Str_Object, $Result->ErrorMessage, 0, "Разработчик");
					$All_Message->Add_Message($Str_Object, "Ошибка получения данных заголовков контента страницы. Ошибка неизвестна", 0, "Разработчик");
					If (isset($Result->ForUser) && $Result->ForUser == True)
						If (isset($Result->UserMessage) && count(trim($Result->UserMessage)) > 0)
							$All_Message->Add_Message($Str_Object, $Result->UserMessage, 0, "Пользователь");
				}
			} Else {
				$All_Message->Add_Message($Str_Object, "Ошибка получения данных заголовков контента страницы. Неизвестный ответ сервиса '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
			}

			$All_Message->Add_Message($Str_Object, "Завершение получения данных заголовков контента страницы", 0, "Разработчик");
			unset($ValueConnection, $Result, $HTTPConnection, $Arr_Params, $ParamMethod, $JSONData, $AnswerService, $Str_Object, $ArrResult);

			return $_ReturnValue;
	###@@@@@@@@@@@@@@@@@@@@@
		}

	###@@@@@@@@@@@@@@@@@@@@@
	###  Считывание данных контента страницы
	### getListOfDocumentsContentsPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue)
	### 	Читает список документов контента страницы из базы методом 1С (WEB запрос)
		private function getListOfDocumentsContentsPageFromBase1CMethod(&$MainConnect, $All_Message, &$SystemValue) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###------- Выходные параметры
	###

			$_ReturnValue = True;
			//ForEach ($this->_Arr_ContentType As $Key => $Value) {            //
			//}

			$Str_Object = "Объект 'Страница портала'";
			$All_Message->Add_Message($Str_Object, "Начало получения данных заголовков контента страницы", 0, "Разработчик");

			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/ws/PortalMaintenance.1cws?wsdl';

			$ValueConnection = $MainConnect->setConnection($All_Message);

			$Result = NULL;
			If ($ValueConnection) {
				Try {
					$Arr_Params = Array(
						"ВидыКонтента" => $this->_Arr_ContentType,
						"НомерСтраницы" => 0
					);

					$JSONData = json_encode($Arr_Params, JSON_UNESCAPED_UNICODE);
					$ParamMethod = array(
							"CodePortal" => Str_PortalIdent,
							"Parameters" => $JSONData
						);

					$HTTPConnection = $MainConnect->ConnectDB;
					$Result = $HTTPConnection->GetPageContentInfo($ParamMethod)->return;
				} Catch(Exception $e) {
					$All_Message->Add_Message($Str_Object, "Ошибка обращения к методу 'GetPageContentInfo()' WEB сервиса '" . $MainConnect->Str_HTTPWSAdress . "'. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
					$MainConnect->insertLogMessage($All_Message ,$e->getMessage());
					$_ReturnValue = False;
					$Result = NULL;
				}
			}
			$MainConnect->Str_HTTPWSAdress = "";

			If ($Result !== NULL && is_object($Result)) {
				If (isset($Result->Error) && $Result->Error == False) {
					$AnswerService = json_decode($Result->Result, True)['#value'];
					$ArrResult = $AnswerService['ListTypesForContentPages'];
					//$this->N_NumPagesInfo = $AnswerService['NumPagesInfo'];
					If (is_array($ArrResult)) {
		 				$this->_Void_Data = $ArrResult;
		 				//$Num_Row = 0;
						//Foreach($ArrResult As &$Value) {

						//}
						//unset($Num_Row);
					} Else {
						$All_Message->Add_Message($Str_Object, "Ошибка получения данных заголовков контента страницы. Некорректные данные ответа", 0, "Разработчик");
					}
					unset($ArrResult);
				} Else {
					$All_Message->Log_GlobalError = True;
					If (isset($Result->ErrorMessage))
						$All_Message->Add_Message($Str_Object, $Result->ErrorMessage, 0, "Разработчик");
					$All_Message->Add_Message($Str_Object, "Ошибка получения данных заголовков контента страницы. Ошибка неизвестна", 0, "Разработчик");
					If (isset($Result->ForUser) && $Result->ForUser == True)
						If (isset($Result->UserMessage) && count(trim($Result->UserMessage)) > 0)
							$All_Message->Add_Message($Str_Object, $Result->UserMessage, 0, "Пользователь");
				}
			} Else {
				$All_Message->Add_Message($Str_Object, "Ошибка получения данных заголовков контента страницы. Неизвестный ответ сервиса '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
			}

			$All_Message->Add_Message($Str_Object, "Завершение получения данных заголовков контента страницы", 0, "Разработчик");
			unset($ValueConnection, $Result, $HTTPConnection, $Arr_Params, $ParamMethod, $JSONData, $AnswerService, $Str_Object, $ArrResult);

			return $_ReturnValue;
	###@@@@@@@@@@@@@@@@@@@@@
		}

	###@@@@@@@@@@@@@@@@@@@@@
	###  Считывание детальных данных контента страницы
	### getDocumentContentPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue, Sring Type, String PID)
	### 	Читает детализацию контента страницы из базы методом 1С (HTTP запрос)
		private function getDocumentContentPageFromBase1CMethod(&$MainConnect, $All_Message, &$SystemValue, $TypeContent, $PIDContent) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  Sring Type							- Тип данных контента
	###  String PID							- Идентификатор данных контента
	###------- Выходные параметры
	###	 Bool - признак удачного выполнения операции
	###

			$_ReturnValue = True;

			$Str_Object = "Объект 'Страница портала'";
			$All_Message->Add_Message($Str_Object, "Начало получения данных детальных данных контента страницы", 0, "Разработчик");

			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/PageContentMaintenanceService/PageContentInfo/' . Str_PortalIdent . '/';

			If ($TypeContent === "Новости") {            	$MainConnect->Str_HTTPWSAdress = $MainConnect->Str_HTTPWSAdress . '01/';			} ElseIf ($TypeContent === "Статьи") {
            	$MainConnect->Str_HTTPWSAdress = $MainConnect->Str_HTTPWSAdress . '02/';
			} ElseIf ($TypeContent === "Проекты") {
            	$MainConnect->Str_HTTPWSAdress = $MainConnect->Str_HTTPWSAdress . '04/';
			}

           	$MainConnect->Str_HTTPWSAdress = $MainConnect->Str_HTTPWSAdress . $PIDContent . '/';

			$HTTPRequest = "GET";
			$HTTPHeader = array('Content-Type: application/json',
							'Content-Language: ru-RU');

			$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest);

			If (is_array($Result) && array_key_exists('Ошибка', $Result) && (bool)$Result['Ошибка'] !== True) {

				//print_r($Result);

				$_ReturnValue = True;

				$ArrResult = Null;
				If (isset($Result['Результат']))
					$ArrResult = $Result['Результат'];

                ///!!!!!
				//print_r($ArrResult);

				If (is_array($ArrResult)) {

					$this->_Void_Data = $ArrResult;

					unset($Argument, $ValueArg);

				} ElseIf (!is_bool($Result)) {
					If (is_array($Result)) {
						If (array_key_exists('ОписаниеОшибки', $Result))
							$All_Message->Add_Message($Str_Object, $Result['ОписаниеОшибки'], 0, "Разработчик");
						If ((bool)$Result['ДляПользователя'] == True)
							$All_Message->Add_Message($Str_Object, $Result['ТекстПользователю'], 0, "Пользователь");
					}
					$All_Message->Add_Message($Str_Object, "Ошибка метода '" . $HTTPRequest . "' обработки свойств контента страницы '" . $MainConnect->Str_HTTPWSAdress . "'.", 0, "Разработчик");
				} Else
					$_ReturnValue = $Result;
				unset($ArrResult);
			} ElseIf (!is_bool($Result)) {
				If (is_array($Result)) {
					If (array_key_exists('ОписаниеОшибки', $Result))
					$All_Message->Add_Message($Str_Object, $Result['ОписаниеОшибки'], 2, "Разработчик");
					If ((bool)$Result['ДляПользователя'] == True)
						$All_Message->Add_Message($Str_Object, $Result['ТекстПользователю'], 2, "Пользователь");
				}
				$All_Message->Add_Message($Str_Object, "Ошибка сервиса при обработке свойств контента страницы '" . $MainConnect->Str_HTTPWSAdress . "'", 2, "Разработчик");
			} Else
				$_ReturnValue = $Result;

			$MainConnect->Str_HTTPWSAdress = "";
			unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest);
			$All_Message->Add_Message($Str_Object, "Завершение получения данных свойств контента страницы", 0, "Разработчик");
			return $_ReturnValue;
	###@@@@@@@@@@@@@@@@@@@@@
		}

	###@@@@@@@@@@@@@@@@@@@@@
	###  Считывание данных контента страницы
	### getTextContentPageFromBase1CMethod(Connections Connection, ErrorOfModul All_Message, SystemConfig SystemValue)
	### 	Читает данные контента страницы из базы методом 1С (HTTP запрос)
		private function getTextContentPageFromBase1CMethod(&$MainConnect, $All_Message, &$SystemValue) {	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###------- Выходные параметры
	###
	###@@@@@@@@@@@@@@@@@@@@@
		}



	////////////////////////////////////////////////////
	}
	######      Конец описания объекта             #####
	####################################################
?>
