<?php
	####################################################
	########   Объект  "Конфигурация приложения"  ######
	####################################################
	class SystemConfig{
	### Наименование - SystemConfig
	###		Объект, в котором содержаться настройки и свойства системы
	###
	###-------------------------------------------------
	###  Требуются объекты для работы
	### ErrorOfModul All_Message		// Объект "Сообщения системы"
	### Connections MainConnect			// Объект "Соединение с БД"
	////////////////////////////////////////////////////
	################    Свойства    ####################
	////////////////////////////////////////////////////
	###////// Открытые
	###
	### Arr_TipesSites;			:Array					- Массив доступных видов сайтов
	### Arr_TypesBaner;			:Array					- Массив доступных видов типов банеров
	### B_UseConfData;			:Boolean				- Признак, что порталом используются конфиденциальные данные
	### B_UseNews;				:Boolean				- Признак, что порталом используется новостная лента
	### B_EngineShow;			:Boolean				- Признак, что версию движка можно показывать на страницах
	### D_DateTermsOfUse;		:Time					- Дата версии правил использования
	###	S_Description;			:String					- Текст краткого описание портала
	###	S_About;				:String					- Текст описание портала для полного описания
	### S_HeaderTermsOfUse;		:String					- Заголовок текста правил использования
	### S_TextTermsOfUse;		:String					- Текст правил использования
	### D_DatePolicySecurity;	:Data					- Дата версии политики безопасности
	### S_HeaderPolicySecurity;	:String					- Заголовок текста политики безопасности
	### S_TextPolicySecurity;	:String					- Текст политики безопасности
	### N_NumPage;				:Integer				- Номер текущей страницы контента
	### N_NumPagesInfo;			:Integer				- Количество страниц для контента страницы
	### B_UseYandexMetriks;		:Boolean				- Использовать Яндекс метрику
	### S_YandexMetriks;		:String					- Текст Яндекс метрики
	### B_UseGoogleMetriks;		:Boolean				- Использовать Google метрику
	### S_GoogleMetriks;		:String					- Текст Google метрики
	### S_ActivePage;			:String					- Наименование активной страницы
	###------------------------------------------------
	###////// Внутренние
	###	B_NS;					:Array					- Массив содержащий данные переменных для обновления
	###	Arr_EMail;				:Array					- Массив настроек EMail сервера
	###								['Use'] 		:Bool		- признак использования EMail сервера
	###								['Server']	 	:String		- Адрес EMail сервера
	###								['SMTP']		:String		- Адрес SMTP сервера
	###								['SMTPPort']	:Int		- Порт для подключения
	###								['SMTPSocket']	:String		- Сокет для подключения
	###								['SMTPNeedPass']:bool		- Признак использования пароля на SMTP подключении
	###								['SMTPLogin']	:String		- Имя пользователя SMTP
	###								['SMTPPassword']:String		- Пароль пользователя SMTP
	###								['Admin']	 	:String		- EMail администратора
	###								['Moderator'] 	:String		- EMail модератора
	###								['Developer'] 	:String		- EMail разработчика
	###								['Robot'] 		:String		- EMail робота
	###	Arr_Counter;			:Array					- массив данных подключения к БД счетчика
	###								['Use'] 		:Bool		- признак использования счетчика
	###								['Name'] 		:String		- Имя БД
	###								['Type'] 		:String		- Тип БД
	###								['HostName'] 	:String		- Имя Host-а
	###								['IP'] 			:String		- IP адрес Host-а
	###								['Port'] 		:Int		- Порт для подключения к БД
	###								['Socket'] 		:String		- Сокет для подключения к БД
	###								['Login'] 		:String		- Имя пользователя БД счетчика, с которым подключаться к БД
	###								['Password'] 	:String		- Пароль пользователя БД счетчика
	###	S_PathFileTemp;			:String					- Путь к временным файлам
	###	S_PathFileLogs;			:String					- Путь к файлам логов
	###	S_NameFileLogs;			:String					- Имя файла логов
	###	S_PathFileBegin;		:String					- Путь до запускного файла
	###	S_FileBegin;			:String					- Имя запускного файла
	###	S_IncludeDir;			:String					- Путь к директории расширкний
	###	S_PictureDir;			:String					- Путь к директории картинок
	###	S_Autor;				:String					- Авторское право
	###	S_Developer;			:String					- Разработчик
	###	B_UseUserAccount;		:Bool					- Признак использования аккаунтов пользователей
	###	B_UseValueBD;			:Bool					- Признак использования настроек БД
	###	B_UseCoockies;			:Bool					- Признак использования Coockies
	###	S_FindContent;			:String					- Поисковый контент портала
	###	B_UseFlash;				:Bool					- Признак использования Flash
	###	S_Version;				:String					- Версия системы
	###	D_DateVersion;			:Date("Y-m-d H:i:s")	- Дата версии системы
	### B_ControlIP;			:Bool					- Применять верификацию по IP адресам
	### B_ControlClient;		:Bool					- Применять верификацию клиента(браузера) пользователя
	###	S_SystemName;			:String					- Наименование приложения
	### S_SiteName;				:String					- Интернет-наименование сайта
	### S_EngineName;			:String					- Наименование двигателя портала
	### S_EngineVersion;		:String					- Версия двигателя портала
	### D_EngineDataVersion;	:Time					- Дата версии двигателя портала
	### Arr_Menu;				:Array					- Массив меню портала
	### Arr_Pages;				:Array					- Массив страниц портала
	###
	###
	###------------------------------------------------
	###////// Требующие реализации
	###
	////////////////////////////////////////////////////
	###########   Методы класса   ######################
	////////////////////////////////////////////////////
	###////// Открытые
	###
	###  __construct(Object Connections, Object ErrorOfModul)
	###										:Oblect		- Конструктор объекта класса
	###  __set(String Name_Var, Void _Value_Var)
	###										:Void		- Установить значение свойства класса
	###  __get(String Name_Var)				:Void		- Прочитать значение переменной
	### setCurrentActivePage(Object Connections, Object ErrorOfModul)
	###										:Bool		- Вычисляет и устанавливает значение реквизита каласса (S_ActivePage)
	### compareValues(Object Connections, Object ErrorOfModul, Bool NeedSave, Array POST)
	###										:Bool		- Сравнение данных БД с введенными пользователем данными
	### getVersion()						:String		- Прочитать версию системы
	### getDataVersion()					:Data		- Прочитать дату версии в формате YYYY-MM-DD CC:MM:SS
	### getUseValueBD()						:Bool		- Прочитать признак, указывающий применять настройки БД
	### getUseAccount()						:Bool		- Прочитать признак, указывающий на использование в системе подситему аккаунтов
	### getUseCoockies()					:Bool		- Прочитать признак, указывающий на использование в системе Coockies
	### getUseFlash()						:Bool		- Прочитать признак, указывающий на использование в системе Flash анимации
	### getCounter()						:Array		- Прочитать настройки для доступа к БД счетчика
	### getEMail()							:Array		- Прочитать настройки для доступа к EMail
	### getAutor()							:String		- Прочитать строку "автор"
	### getDeveloper()						:String		- Прочитать строку "Разработчик"
	### getIncludeDir()						:String		- Прочитать директорию подключаемых модулей
	### getPictureDir()						:String 	- Прочитать директорию храниния картинок
	### getScriptDir()						:String		- Прочитать директорию храниния скриптов
	### getCGIScriptDir()					:String		- Прочитать директорию храниния скриптов FastCGI
	### getStylesDir()						:String		- Прочитать директорию храниния описания стилей
	### getTempDir()						:String 	- Прочитать директорию храниния временных файлов
	### getLogFile()						:String		- Прочитать путь с именем файла логов
	### getNameLogFile()					:String		- Прочитать имя файла логов
	### getPathLogFile()					:String		- Прочитать путь файла логов
	### getControlIP()						:Bool		- Получить значение признака контроля по IP адресам
	### getControlClient()					:Bool		- Получить значение признака контроля клиента(браузера) пользователя
	### getSystemName()						:String		- Получить наименование приложения
	### getSiteName()						:String		- Получить Интернет-наименование сайта
	### getFileBegin()						:String		- Прочитать HTTP начальный файл
	### getPathBegin()						:String		- Прочитать HTTP путь заголовок начальной страницы
	### getEngineVersion()					:String		- Прочитать значение версии движка считанной из БД
	### getEngineVersion()					:String 	- Прочитать значение версии движка считанной из БД
	### getEngineDataVersion()				:Data		- Прочитать значение даты версии движка считанной из БД
	### getMenuPortal()						:Array		- Получить значение переменной класса Меню
	### getArrayPagesPortal()				:Array		- Получить значение переменной класса Страницы портала
	### ConfirmEMailByText(Object Connections, Object ErrorOfModul, String S_TextConfirm)
	###										:bool		- Подтверждение адреса электронной почты
	### insertLogMessage()					:Bool		- записать ошибки в файлы и в объект "собщения"
	### ReadTypesSites(Object Connections, Object ErrorOfModul)
	### 									:Array 		- прочитать типы возможных страниц в виде дерева
	### readTermsOfUse(Object Connections, Object ErrorOfModul)
	### 									:Bool		- инициировать чтение текста правил использования
	### readPolicySecurity(Object Connections, Object ErrorOfModul)
	### 									:Bool		- инициировать чтение текста политики безопасности
	### getHTMLTextListTypeBaners(Object Connections, Object ErrorOfModul, Array Parameters)
	###										:String		- Получить HTML текст для страницы со списком типов банеров ресурсов
	### getHTMLTextListPages(Object ErrorOfModul, Array GET, String AdresPage)
	###										:String		- Получить HTML список ссылок нумераций страниц
	### updateServices(Object Connection, Object ErrorOfModul, Array Arr_Data)
	###										:Bool		- инициировать выполнение метода сервиса обслуживания
	###
	###------------------------------------------------
	###////// Защищенные
	### saveConfig(Object Connections, Object ErrorOfModul, Array SaveData)
	###										:Bool		- Сохранить данные объекта в базу данных
	### setValueClassVar(String Argument, Void Value)	- Инициализация установки переменной класса
	### FindTypeBanerBySID(String Value)
	### 									: Link BanerType	- Получить ссылку на тип банера
	### readTermsOfUseFromBaseHTTPMethod(Object Connections, Object ErrorOfModul)
	### 									:Bool		- прочитать текст правил использования HTTP методом
	### readPolicySecurityFromBaseHTTPMethod(Object Connections, Object ErrorOfModul)
	### 									:Bool		- прочитать текст политики безопасности HTTP методом
	### updateData1CMethod(Object Connection, Object ErrorOfModul, Array Arr_Data)
	###										:Bool		- выполнить метод сервиса обслуживания порталов сервисными службами методом HTTP 1С
	### updateDataPHPMethod(Object Connection, Object ErrorOfModul, Array Arr_Data)
	###										:Bool		- выполнить метод сервиса обслуживания порталов сервисными службами внутренним методом
	###
	###------------------------------------------------
	###////// Внутренние
	###
	### CorrectProperty(Array SessionArray)				- Дополнить данные временного массива Сессии
	###
	////////////////////////////////////////////////////
	##########      Свойства класса        #############
	////////////////////////////////////////////////////
	### Открытые свойств1а
		public $Arr_TipesSites;				// Массив доступных видов сайтов
		public $Arr_TypesBaner;				// Массив доступных видов типов банеров
		public $S_SystemName;				// Наименование приложения
		public $S_SiteName;					// Интернет-наименование сайта
		public $S_Description;				// Текст краткого описание портала
		public $S_About;					// Описание интернет портала
		public $S_FindContent;              // Поисковый контент портала
		public $S_Version;					// Версия системы
		public $D_DateVersion;				// Дата версии системы
		public $S_EmailContact;				// Почта контактная
		public $S_EmailTechService;			// Почта технической поддержки
		public $S_TelefonContact;			// Телефон контактная
		public $S_TelefonTechService;		// Телефон технической поддержки
		public $S_Autor;					// Авторское право
		public $S_Designer;					// Дизайнер
		public $S_Developer;				// Разработчик
		public $B_UseConfData;				// Признак, что порталом используются конфиденциальные данные
		public $B_UseNews;					// Признак, что порталом используется новостная лента
		public $B_EngineShow;				// Признак, что версию движка можно показывать на страницах
		public $D_DateTermsOfUse;			// Дата версии правил использования
		public $S_HeaderTermsOfUse;			// Заголовок текста правил использования
		public $S_TextTermsOfUse;			// Текст правил использования
		public $D_DatePolicySecurity;		// Дата версии политики безопасности
		public $S_HeaderPolicySecurity;		// Заголовок текста политики безопасности
		public $S_TextPolicySecurity;		// Текст политики безопасности
		public $N_NumPage;                  // Номер текущей страницы контента
		public $N_NumPagesInfo;				// Количество страниц для контента страницы
		public $B_UseYandexMetriks;			// Использовать Яндекс метрику
		public $S_YandexMetriks;			// Текст Яндекс метрики
		public $B_UseGoogleMetriks;			// Использовать Google метрику
		public $S_GoogleMetriks;			// Текст Google метрики
		public $S_ActivePage;				// Наименование активной страницы
	### Закрытые свойства
		private $B_NS;						// Массив содержащий массив текущих данных, для сравнения с данными введенными пользователем
		private $Arr_EMail;					// Использовать EMail сервер для рассылки
		private $Arr_Counter;				// Массив данных подключения к БД счетчика
		private $S_PathFileTemp;			// Путь к временным файлам
		private $S_PathFileLogs;			// Путь к файлам логов
		private $S_NameFileLogs;			// Имя файла логов
		private $S_PathFileBegin;			// Путь до запускного файла
		private $S_FileBegin;				// Имя запускного файла
		private $S_IncludeDir;				// Путь к директории расширкний
		private $S_PictureDir;				// Путь к директории картинок
		private $S_ScriptDir;				// Путь к директории скриптов
		private $S_CGIScriptDir;			// Путь к директории FastCGI скриптов
		private $S_StylesDir;				// Путь к директории FastCGI скриптов
		private $B_UseUserAccount;			// Признак использования аккаунтов пользователей
		private $B_UseValueBD;				// Признак использования настроек БД
		private $B_UseCoockies;				// Признак использования Coockies
		private $B_UseFlash;				// Признак использования Flash
		private $B_ControlIP;				// Применять верификацию по IP адресам
		private $B_ControlClient;			// Применять верификацию клиента(браузера) пользователя
		private $S_EngineName;				// Наименование двигателя портала
		private $S_EngineVersion;			// Версия двигателя портала
		private $D_EngineDataVersion;		// Дата версии двигателя портала
		private $N_StepPages;				// Шаг для отображения номеров страниц на странице
		private $Arr_Menu;					// Массив меню портала
		private $Arr_Pages;					// Массив страниц портала

	////////////////////////////////////////////////////
	##########        Методы класса        #############
	////////////////////////////////////////////////////

	###////// Открытые

	###@@@@@@@@@@@@@@@@@@@@@
	### Конструктор
	### __construct(Connections Connections, ErrorOfModul ErrorOfModul)
	### 	Конструктор класса
		function __construct(Connections $MainConnect, ErrorOfModul $All_Message, Array $Arr_Sess) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  Array Data							- Массив данных сессии
	###------- Выходные параметры
	###  Object - объект типа "SystemConfig"
	###
			// Задаю первоначальные значения
			$this->B_UseConfData = False;				// Признак, что порталом используются конфиденциальные данные
			$this->B_UseNews = False;					// Признак, что порталом используется новостная лента
			$this->B_EngineShow = False;
			$this->S_EngineName = "";
			$this->S_EngineVersion = "";
			$this->S_Description = "";					// Текст краткого описание портала
			$this->S_About = "";						// Текст описание портала
			$this->D_EngineDataVersion = time();
			$this->D_DateTermsOfUse = time();			// Дата версии правил использования
			$this->S_HeaderTermsOfUse = "";				// Заголовок текста правил использования
			$this->S_TextTermsOfUse = "";				// Текст правил использования
			$this->D_DatePolicySecurity = time();		// Дата версии политики безопасности
			$this->S_HeaderPolicySecurity = "";			// Заголовок текста политики безопасности
			$this->S_TextPolicySecurity = "";			// Текст политики безопасности
			$this->N_NumPage = 0;
			$this->N_NumPagesInfo = 0;
			$this->N_StepPages = 2;
			$this->S_IncludeDir = "include/";			// Путь к директории скриптов
			$this->S_PictureDir = "images/";			// Путь к директории скриптов
			$this->S_ScriptDir = "jQuery/";				// Путь к директории скриптов
			$this->S_CGIScriptDir = "CGI-local/";		// Путь к директории FastCGI скриптов
			$this->S_StylesDir = "styles/";				// Путь к директории FastCGI скриптов
			$this->B_UseYandexMetriks = False;			// Использовать Яндекс метрику
			$this->S_YandexMetriks = "";				// Текст Яндекс метрики
			$this->B_UseGoogleMetriks = False;			// Использовать Google метрику
			$this->S_GoogleMetriks = "";				// Текст Google метрики
			$this->Arr_Menu = Array();                  // Массив меню портала
			$this->Arr_Pages = Array();					// Массив страниц портала
			$this->S_ActivePage = "Стартовая";			// Наименование активной страницы

			// Читаю данные из базы
			$All_Message->Add_Message("Приложение", "Начало получения данных портала", 0, "Разработчик");
			If ($MainConnect->Boo_Use1CManager == True) {
				//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
				//	http://noutpc/ManagerPortals/hs/PortalMaintenanceService/PortalInfo/ROP00000000000000002/
				$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/PortalMaintenanceService/PortalInfo/' . Str_PortalIdent . '/';
                //echo $Str_hsAdress;
                $HTTPHeader = array('Content-Length: 0',
					                'Accept: application/json');
                $HTTPRequest = "GET";

				$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest);

				If (is_array($Result) && array_key_exists('Ошибка', $Result) && (bool)$Result['Ошибка'] !== True) {

					//print_r($Result);

					$ReturnValue = True;

					$ArrResult = Null;
					If (isset($Result['Результат']))
						$ArrResult = $Result['Результат'];

					//print_r($ArrResult);

					If (is_array($ArrResult)) {

						Foreach($ArrResult As $Value) {
							$Argument = $Value['Наименование'];
							$ValueArg = $Value['Значение'];

							$this->setValueClassVar($Argument, $ValueArg);
						}

						$this->setCurrentActivePage($Arr_Sess['S_ServerRequestUri']);

						unset($Argument, $ValueArg);

					} ElseIf (!is_bool($Result)) {
						If (is_array($Result)) {
							If (array_key_exists('ОписаниеОшибки', $Result))
								$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 0, "Разработчик");
							If ((bool)$Result['ДляПользователя'] == True)
								$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 0, "Пользователь");
						}
						$All_Message->Add_Message("Приложение", "Ошибка метода '" . $HTTPRequest . "' обработки свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'.", 0, "Разработчик");
					} Else
						$ReturnValue = $Result;
					unset($ArrResult);
				} ElseIf (!is_bool($Result)) {
					If (is_array($Result)) {
						If (array_key_exists('ОписаниеОшибки', $Result))
						$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 2, "Разработчик");
						If ((bool)$Result['ДляПользователя'] == True)
							$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 2, "Пользователь");
					}
					$All_Message->Add_Message("Приложение", "Ошибка сервиса при обработке свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'", 2, "Разработчик");
				} Else
					$ReturnValue = $Result;

				$MainConnect->Str_HTTPWSAdress = "";

				unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest);

			} Else {
				// Переменные
				// Выполнить запрос
				$SQL_Query = "SELECT `ArgumentName`, `Value`, `DinamicFieldName`, `FieldType`, `ThisWord` FROM `CFGTable`";
				$MainConnect->SQLQuery = $SQL_Query;
				If ($Result = $MainConnect->execSQLQuery($All_Message, $this)) {
					// проход по результату запроса, перебором строк и присвоение переменным - значений из строк результата запроса
					While ($Row = $Result->fetch_row()) {
						// выборочное присвоение данных
						$Argument = trim((string)$Row[0]);
						$TypeField = intval($Row[3]);
						If ($TypeField === 1)
							$Value = stripslashes(trim((string)$Row[1]));
						Elseif ($TypeField === 2)
							$Value = intval($Row[1]);
						Elseif ($TypeField === 3)
							$Value = floatval($Row[1]);
						Elseif ($TypeField === 4) {
							$Value = (bool)$Row[1];
							If ($Value == 1)
								$Value = True;
							Else
								$Value = False;
						}
						Elseif ($TypeField === 5)
							$Value = date("Y-m-d H:i:s", strtotime((string)$Row[1]));

						$Arr_ForSave = Array("Value" => $Value, "NameField" => trim((string)$Row[2]), "TypeField" => $TypeField, "ThisWord" => (bool)$Row[4]);
						$this->B_NS[$Argument] = $Arr_ForSave;

						$this->setValueClassVar($Argument, $Value);

					}
					$Result->close();
				} Else {					$All_Message->Log_GlobalError = True;
				}

				// Скорректировать массив свойств сессии
				$this->CorrectProperty($Arr_Sess);

				If (isset($Result))
					unset($Result);
				If (isset($_ConnectDB))
					unset($_ConnectDB);
				If (isset($Row))
					unset($Row);
				If (isset($e))
					unset($e);
				unset($SQL_Query);
			}

			$All_Message->Add_Message("Приложение", "Завершение получения данных портала", 0, "Разработчик");
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### __set(String Name_Var, Void _Value_Var)
	### 	Установка значений класса
		function __set($_Name_Var, $_Value_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###  Void _Value_Var			- Значение переменной
	###------- Выходные параметры
	###  bool - признак удачной операции
	###
			//$this->$_Name_Var = $_Value_Var;

			return true;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### __get(String Name_Var)
	### 	Считывание значений свойств класса
		function __get($_Name_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###------- Выходные параметры
	###  Void _Value_Var		- Значение переменной
	###
			return False;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setCurrentActivePage(Object Connections, Object ErrorOfModul)
	### 	вычисляет и устанавливает значение реквизита каласса (S_ActivePage)
		public function setCurrentActivePage($Value) {
	###------- Входные параметры
	###  String Value			- Объект содержащий сведения о подключении
	###------- Выходные параметры
	###  Boolean - признак успешно завершенной операции
	###
			$ReturnValue = True;

			If (strlen($Value) > 0)
				ForEach ($this->Arr_Pages As $PageValue) {					$_S_Temp = '/' . $PageValue['АдреснаяСтрока'] . '/i';					If (preg_match($_S_Temp, $Value)) {						$this->S_ActivePage = $PageValue['НаименованиеКраткое'];					}				}

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readTermsOfUse(Object Connections, Object ErrorOfModul)
	### 	инициировать чтение текста правил использования
		public function readTermsOfUse(Connections $MainConnect, ErrorOfModul $All_Message) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Boolean - признак успешно завершенной операции
	###

			$ReturnValue = False;

			// Читаю данные из базы
			$All_Message->Add_Message("Приложение", "Начало получения данных портала", 0, "Разработчик");
			If ($MainConnect->Boo_Use1CManager == True) {
				$ReturnValue = $this->readTermsOfUseFromBaseHTTPMethod($MainConnect, $All_Message);
			} Else {
			}

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readPolicySecurity(Object Connections, Object ErrorOfModul)
	### 	инициировать чтение текста политики безопасности
		public function readPolicySecurity(Connections $MainConnect, ErrorOfModul $All_Message) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Boolean - признак успешно завершенной операции
	###

			$ReturnValue = False;

			// Читаю данные из базы
			$All_Message->Add_Message("Приложение", "Начало получения данных портала", 0, "Разработчик");
			If ($MainConnect->Boo_Use1CManager == True) {
				$ReturnValue = $this->readPolicySecurityFromBaseHTTPMethod($MainConnect, $All_Message);
			} Else {

			}

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### ReadTypesSites(Object Connections, Object ErrorOfModul)
	### 	прочитать типы возможных страниц
		public function ReadTypesSites(Connections $MainConnect, ErrorOfModul $All_Message) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Array - дерево доступных видов страниц
	###
			//$ReturnValue = array();
			$ObjectsTypeBaner = array();

			$All_Message->Add_Message("Объект 'Приложение'", "Начало получения данных типов банеров", 0, "Разработчик");

			if ($MainConnect->Boo_Use1CManager == True) {

                $MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/ws/PortalMaintenance.1cws?wsdl';

                $_ReturnValue = $MainConnect->setConnection($All_Message);

				$Result = NULL;
				if ($_ReturnValue) {
					try {						/*
						$data = array
							(
								"Идентификатор"		=> $this->_P_ID  // Идентификатор пользователя, что бы отобрать только порталы этого пользователя
							);
						$JSONData = json_encode($data);
						*/
						$_paramMethod = array (
								//"CodePortal" => Str_PortalIdent
								//,
								//"Parameters" => $JSONData
							);

                        $HTTPConnection = $MainConnect->ConnectDB;
						$Result = $HTTPConnection->GetTypesBanersInfo($_paramMethod)->return;
					} catch(Exception $e) {
						$All_Message->Add_Message("Объект 'Приложение'", "Ошибка обращения к методу 'GetTypesBanersInfo()' WEB сервиса. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
						$MainConnect->insertLogMessage($All_Message ,$e->getMessage());
						$_ReturnValue = False;
						$Result = NULL;
					}
				}
				$MainConnect->Str_HTTPWSAdress = "";

				If ($Result !== NULL && is_object($Result)) {					if (isset($Result->Error) && $Result->Error == false) { // && isset($Result->enc_value->TypesBaners)) {
						$ArrResult = json_decode($Result->Result, true)['#value'];
						if (is_array($ArrResult)) {
							$N_IndexRow = 0;
							Foreach($ArrResult As $Value) {								$ObjTypeBaner = new BanerType($Value['SID']);
								$ObjTypeBaner->setPID($Value['PID']);
								$ObjTypeBaner->_S_Parent = $Value['ParentSID'];
								$ObjTypeBaner->_S_PublicName = $Value['PublicName'];
								$ObjTypeBaner->_S_ImageNum = $Value['PictureID'];
								$ObjTypeBaner->_S_Description = $Value['Description'];
								$ObjectsTypeBaner[$N_IndexRow]['Obj'] = $ObjTypeBaner;
								$ObjectsTypeBaner[$N_IndexRow]['ID'] = $Value['SID'];
								$ObjectsTypeBaner[$N_IndexRow]['Parent_ID'] = $Value['ParentSID'];
								unset($ObjTypeBaner);
								$N_IndexRow ++;
							}
							unset($N_IndexRow);
						} else {
							$All_Message->Add_Message("Объект 'Приложение'", "Ошибка получения данных о типах банеров. Некорректные данные ответа", 0, "Разработчик");
						}
						unset($ArrResult);
					} else {
						$All_Message->Log_GlobalError = True;
						if (isset($Result->ErrorMessage))
							$All_Message->Add_Message("Объект 'Приложение'", $Result->ErrorMessage, 0, "Разработчик");
						$All_Message->Add_Message("Объект 'Приложение'", "Ошибка получения данных о типах банеров. Ошибка неизвестна", 0, "Разработчик");
					}
				} else {
					$All_Message->Add_Message("Объект 'Приложение'", "Ошибка получения данных о типах банеров. Неизвестный ответ сервиса", 0, "Разработчик");
				}

				unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest);

			}
			else {
				$SQL_Query = "SELECT `ID`, `KodPage`, `IDParent`, `NameType`, `ImageID`, `Descripton` FROM `typessytes`";

				$MainConnect->SQLQuery = $SQL_Query;
				if ($Result = $MainConnect->execSQLQuery($All_Message, $this)) {					$N_IndexRow = 0;
					while ($Row = $Result->fetch_row()) {

						$ReturnValue[$N_IndexRow]['ID'] = (string)$Row[0];
						$ReturnValue[$N_IndexRow]['PID'] = (int)$Row[1];
						$ReturnValue[$N_IndexRow]['Parent_ID'] = (string)$Row[2];
						$ReturnValue[$N_IndexRow]['NameType'] = trim((string)$Row[3]);
						$ReturnValue[$N_IndexRow]['ImageID'] = trim((string)$Row[4]);
						$ReturnValue[$N_IndexRow]['Description'] = trim((string)$Row[5]);

						$ObjTypeBaner = new BanerType((string)$Row[0]);
						$ObjTypeBaner->setPID((int)$Row[1]);
						$ObjTypeBaner->_S_Parent = (string)$Row[2];
						$ObjTypeBaner->_S_PublicName = (string)$Row[3];
						$ObjTypeBaner->_S_ImageNum = (string)$Row[4];
						$ObjTypeBaner->_S_Description = (string)$Row[5];
						$ObjectsTypeBaner[$N_IndexRow]['Obj'] = $ObjTypeBaner;
						$ObjectsTypeBaner[$N_IndexRow]['ID'] = (string)$Row[0];
						$ObjectsTypeBaner[$N_IndexRow]['Parent_ID'] = (string)$Row[2];

						unset($ObjTypeBaner);

						$N_IndexRow ++;
					}
					unset($N_IndexRow);
				}
				unset($Result, $SQL_Query);
			}

			//print_r($ObjectsTypeBaner);
			$this->Arr_TypesBaner = array();
			//Построение иерархического массива объекта
			$ObjectsTypeBaner = Array_To_Tree($ObjectsTypeBaner);
		    foreach ($ObjectsTypeBaner as &$Value) {				$ObjectArray = array();
				$ObjectArray['Object'] = &$Value['Obj'];

				$ChildArray = array();
				if (isset($Value['Children'])) {
				    foreach ($Value['Children'] as &$ChildValue) {				    	$ChildArray[]['Object'] = &$ChildValue['Obj'];					}
				}
			    $ObjectArray['Children'] = $ChildArray;

				$this->Arr_TypesBaner[] = $ObjectArray;
		    }

			$All_Message->Add_Message("Объект 'Приложение'", "Завершение получения данных типов банеров", 0, "Разработчик");

		    return $this->Arr_TypesBaner;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### __construct(Object Connections, Object ErrorOfModul)
	### 	Конструктор класса
		public function RedirectInLinkAddr(Connections $MainConnect, ErrorOfModul $All_Message, Array $Arr_Params) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array Data					- Массив данных сессии
	###------- Выходные параметры
	###  Object - объект типа "SystemConfig"
	###

			$All_Message->Add_Message("Приложение", "Инициализация перенаправления на ресурс", 0, "Разработчик");
			if ($MainConnect->Boo_Use1CManager == True) {

				//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
				//	http://noutpc/ManagerPortals/hs/PortalMaintenanceService/PortalInfo/ROP00000000000000002/
				$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/PortalMaintenanceService/PortalRedirectInfo/' . Str_PortalIdent . '/';

                $HTTPHeader = array('Content-Type: application/json',
							'Content-Language: ru-RU');
                $HTTPRequest = "POST";

				$_paramMethod = array (
						"CodePortal" => Str_PortalIdent,
						"LinkResurs" => $Arr_Params["LinkResurs"]
				);
				if (isset($Arr_Params["SelBaner"]) && $Arr_Params["SelBaner"] !== "")
					$_paramMethod["SelBaner"] = $Arr_Params["SelBaner"];
				$JSONData = json_encode($_paramMethod, JSON_UNESCAPED_UNICODE);

				$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest, $JSONData);

				If ($Result !== NULL) {
					//print_r($Result);

					If ($Result['Ошибка'] == false) {

						/*
						$ArrResult = $Result['Результат'];

						if (is_array($ArrResult)) {
							Foreach($ArrResult As $Value) {
								$Argument = $Value['Наименование'];
								$ValueArg = $Value['Значение'];

								$this->setValueClassVar($Argument, $ValueArg);
							}
							unset($Argument, $ValueArg);
						} else {
							$All_Message->Add_Message("Приложение", "Ошибка обработки ссылки перенаправления на ресурсе '" . $MainConnect->Str_HTTPWSAdress . "'. Некорректные данные", 0, "Разработчик");
						}
						unset($ArrResult);
						*/
					} else {
						$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 0, "Разработчик");
						$All_Message->Add_Message("Приложение", "Ошибка метода '" . $HTTPRequest . "' сервиса при обработке данных ссылки перенаправления '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
					}
				} else {
					$All_Message->Add_Message("Приложение", "Ошибка метода '" . $HTTPRequest . "' обработки ссылки перенаправления при обращении к сервису. Неизвестная ошибка сервиса '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
				}
				$MainConnect->Str_HTTPWSAdress = "";

				unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest);

			} else {
				// Переменные
				// Выполнить запрос
				$SQL_Query = "";
				$MainConnect->SQLQuery = $SQL_Query;
				if ($Result = $MainConnect->execSQLQuery($All_Message, $this)) {
					// проход по результату запроса, перебором строк и присвоение переменным - значений из строк результата запроса
					//while ($Row = $Result->fetch_row()) {
					//}
					$Result->close();
				} else {
					$All_Message->Log_GlobalError = True;
				}

				// Скорректировать массив свойств сессии
				$this->CorrectProperty($Arr_Sess);

				if (isset($Result))
					unset($Result);
				unset($SQL_Query);
			}

			$All_Message->Add_Message("Приложение", "Завершение процедуры перенаправления на ресурс сети", 0, "Разработчик");
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### FindTypeBanerBySID(String SID)
	### Получить ссылку на тип банера
		public function FindTypeBanerBySID($SID) {
	###------- Входные параметры
	###  String SID			- код типа банера для поиска
	###------- Выходные параметры
	###  Link BanerType		- ссылка на тип банера
	###
			$_ReturnValue = Null;

			if (strlen($SID) > 0) {				$_ReturnValue = $this->FindTypeBanerRecurse($this->Arr_TypesBaner, $SID);			}

			return $_ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### compareValues(Object Connections, Object ErrorOfModul, Bool NeedSave, Array POST)
	### 	сравнение значений базы данных со значениями введенными пользователем
		public function compareValues($MainConnect, $All_Message, $NeedSave, $PostArray) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Bool NeedSave				- признак необходимости записи данных
	###------- Выходные параметры
	###  Bool - возвращает признак удачного выполнения функции
	###

			// Переменные

			//Обработка переменной - Наименование приложения
			//$this->compareDataArray($this->B_NS, $All_Message);
			$NewArrayValues = $this->B_NS;

			foreach($NewArrayValues as &$Value) {				if ($Value["TypeField"] === 1) {
					if (isset($PostArray[$Value["NameField"]])) {
						@$NewValue = trim((string)$PostArray[$Value["NameField"]]);
						if (is_string($NewValue))
							if (controlInputField($All_Message, $NewValue, $Value["ThisWord"]))
								if ($Value["Value"] <> $NewValue)
									$Value["Value"] = $NewValue;
					}
				}
				elseif ($Value["TypeField"] === 2){
					if (isset($PostArray[$Value["NameField"]])) {
						@$NewValue = intval($PostArray[$Value["NameField"]]);
						if (is_int($NewValue))
							if ($Value["Value"] <> $NewValue)
								$Value["Value"] = $NewValue;
					}
				}
				elseif ($Value["TypeField"] === 3){
					if (isset($PostArray[$Value["NameField"]])) {
						@$NewValue = floatval($PostArray[$Value["NameField"]]);
						if (is_float($NewValue))
							if ($Value["Value"] <> $NewValue)
								$Value["Value"] = $NewValue;
					}
				}
				elseif ($Value["TypeField"] === 4) {
					if (isset($PostArray[$Value["NameField"]]))
						$NewValue = true;
					else
						$NewValue = false;
					if ($Value["Value"] != $NewValue)
						$Value["Value"] = $NewValue;
				}
				elseif ($Value["TypeField"] === 5) {
					if (isset($PostArray[$Value["NameField"]])) {						@$NewValue = (string)$PostArray[$Value["NameField"]];
						if (is_string($NewValue))
//							if (controlInputField($All_Message, $NewValue, true)){
							try {
								$NewValue = date("Y-m-d H:i:s", strtotime($NewValue));
								if ($Value["Value"] != $NewValue)
									$Value["Value"] = $NewValue;
							}
							catch (Exception $e){							}
//							}
					}
				}
			}

			if ($this->B_NS === $NewArrayValues)
				$RetunResult = false;
			else
				$RetunResult = true;
/*
foreach ($this->B_NS as $Value) {	echo print_r($Value) . "<br />";
}

foreach ($NewArrayValues as $Value) {
	echo print_r($Value) . "<br />";
}
*/

			if ($NeedSave && $RetunResult)				$RetunResult = $this->saveConfig($MainConnect, $All_Message, $NewArrayValues);

			return $RetunResult;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getPathBegin()
	### 	прочитать HTTP путь заголовок начальной страницы
		public function getPathBegin() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_PathFileBegin;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getFileBegin()
	### 	прочитать HTTP начальный файл
		public function getFileBegin() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_FileBegin;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getPictureDir()
	### 	прочитать директорию храниния картинок
		public function getPictureDir() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_PictureDir;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getScriptDir()
	### 	прочитать директорию храниния скриптов
		public function getScriptDir() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_ScriptDir;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getCGIScriptDir()
	### 	прочитать директорию храниния скриптов FastCGI
		public function getCGIScriptDir() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_CGIScriptDir;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getStylesDir()
	### 	прочитать директорию храниния описания стилей
		public function getStylesDir() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_StylesDir;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getTempDir()
	### 	прочитать директорию храниния картинок
		public function getTempDir() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_PathFileTemp;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getLogFile()
	### 	прочитать путь с именем файла логов
		public function getLogFile() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_PathFileLogs . $this->S_NameFileLogs;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getNameLogFile()
	### 	прочитать имя файла логов
		public function getNameLogFile() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_NameFileLogs;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getPathLogFile()
	### 	прочитать путь файла логов
		public function getPathLogFile() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_PathFileLogs;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getEngineName()
	### 	прочитать имя движка платформы
		public function getEngineName() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_EngineName;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getEngineVersion()
	### 	прочитать значение версии движка считанной из БД
		public function getEngineVersion() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_EngineVersion;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getEngineDataVersion()
	### 	прочитать значение даты версии движка считанной из БД
		public function getEngineDataVersion() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Data - значение внутренней переменной
	###
			return $this->D_EngineDateVersion;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getVersion()
	### 	вернуть значение версии считанной из БД
		public function getVersion() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_Version;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getDataVersion()
	### 	вернуть значение даты версии считанной из БД
		public function getDataVersion() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Data - значение внутренней переменной
	###
			return $this->D_DateVersion;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUseValueBD()
	### 	прочитать значение признака использования значений настроек из БД
		public function getUseValueBD() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Bool - значение внутренней переменной
	###
			return $this->B_UseValueBD;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUseAccount()
	### 	прочитать значение признака использования подсистемы аккаунтов
		public function getUseAccount() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Bool - значение внутренней переменной
	###
			return $this->B_UseUserAccount;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUseCoockies()
	### 	прочитать значение признака использования Coockies для доступа ко всем функциям
		public function getUseCoockies() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Bool - значение внутренней переменной
	###
			return $this->B_UseCoockies;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUseFlash()
	### 	прочитать значение признака использования Flash в контенте системы
		public function getUseFlash() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Bool - значение внутренней переменной
	###
			return $this->B_UseFlash;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getCounter()
	### 	прочитать массив настроек подключения к БД счетчика
		public function getCounter() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Array - значение внутренней переменной
	###
			return $this->Arr_Counter;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getEMail()
	### 	прочитать массив настроек подключения к БД счетчика
		public function getEMail() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Array - значение внутренней переменной
	###
			return $this->Arr_EMail;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getAutor()
	### 	прочитать строку "Автор"
		public function getAutor() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_Autor;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getIncludeDir()
	### 	прочитать директорию подключаемых модулей
		public function getIncludeDir() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_IncludeDir;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getDeveloper()
	### 	прочитать строку "Разработчик"
		public function getDeveloper() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - значение внутренней переменной
	###
			return $this->S_Developer;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getSystemName()
	### 	Получить наименование приложения
		public function getSystemName() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  :String	- значение свойства класса
	###
			return $this->S_SystemName;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getSiteName()
	### 	Получить Интерент-наименование сайта
		public function getSiteName() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  :String	- значение свойства класса
	###
			return $this->S_SiteName;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getControlIP()
	### 	Получить значение признака контроля по IP адресам
		public function getControlIP() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  :Bool	- значение свойства класса
	###
			return $this->B_ControlIP;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getControlClient()
	### 	Получить значение признака контроля клиента(браузера) пользователя
		public function getControlClient() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  :Bool	- значение свойства класса
	###
			return $this->B_ControlClient;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getMenuPortal()
	### 	Получить Получить значение переменной класса Меню
		public function getMenuPortal() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  :Array	- значение свойства класса
	###
			return $this->Arr_Menu;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getArrayPagesPortal()
	### 	Получить значение переменной класса Страницы портала
		public function getArrayPagesPortal() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  :Array	- значение свойства класса
	###
			return $this->Arr_Pages;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### ConfirmEMailByText(Object Connections, Object ErrorOfModul, String S_EMail, String S_TextConfirm)
	###		Подтвердить адрес электронной почты
		public function ConfirmEMailByText($MainConnect, $All_Message, $S_EMail, $S_TextConfirm) {	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  String $S_EMail			- EMail для подтверждения
	###  String S_TextConfirm		- срока содержащая код подтверждения
	###------- Выходные параметры
	###  Bool 	- признак выполненной функции
	###
			$ReturnValue = True;

			if ($MainConnect->Boo_Use1CManager == True) {
				//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
				//	http://localhost/ManagerPortals/hs/UsersMaintenanceService/UserLogin/ROP00000000000000002/
				$Str_hsAdress = Str_HostName . '/' . Str_DBName . '/hs/PortalMaintenanceService/ConfirmEMailByString/' . Str_PortalIdent . '/';

				//Получение файла JSON используя curl
				//Инициализация
				$Obj_ch = curl_init();
 				$data = array (
					"Адрес" => $S_EMail,
					"СтрокаПодтверждения" => $S_TextConfirm
				);
	 			$json_data = json_encode($data, JSON_UNESCAPED_UNICODE);

				// Заполняем параметры CURL для получения данных по запросу GET
				curl_setopt($Obj_ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
				curl_setopt($Obj_ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json', 'Content-Language: ru-RU'));
				curl_setopt($Obj_ch, CURLOPT_USERPWD, Str_AccountName . ":" . Str_AccountPass);
				curl_setopt($Obj_ch, CURLOPT_URL, $Str_hsAdress);
				curl_setopt($Obj_ch, CURLOPT_RETURNTRANSFER, True);
				curl_setopt($Obj_ch, CURLOPT_CUSTOMREQUEST, "PUT");
				curl_setopt($Obj_ch, CURLOPT_CONNECTTIMEOUT, 2);
				curl_setopt($Obj_ch, CURLOPT_TIMEOUT, 3);
				curl_setopt($Obj_ch, CURLOPT_POSTFIELDS, $json_data);

				// Выполнение запроса и получение ответа
				$ResponseJson = curl_exec($Obj_ch);

				// Проверка наличия ошибок
				if ($ResponseJson === False) {
					//echo "Ошибка обращения к сервису";
					$str = 'Ошибка выполнения запроса ' . curl_error($Obj_ch) . ' для сервиса ' . $Str_hsAdress . '. Код ошибки: ' . curl_errno($Obj_ch);
					$All_Message->Add_Message("Объект 'Приложение'", $str, 0, "Разработчик");
					$All_Message->Add_Message("Объект 'Приложение'", "Ошибка работы сайта. Выполните операцию позже", 0, "Пользователь");
					$ReturnValue = False;
				} else {
					//Выводим сервисную информацию по выполнению запроса
					$info = curl_getinfo($Obj_ch);
					$str = 'Время выполнения запроса ' . $info['total_time'] . ' секунд для сервиса ' . $info['url'];
					$All_Message->Add_Message("Объект 'Приложение'", $str, 0, "Разработчик");

					$Result = json_decode($ResponseJson, True);

					if (!isset($Result)) {
						$str = 'Ошибка выполнения запроса ' . curl_error($Obj_ch) . ' для сервиса ' . $Str_hsAdress . '. Код ошибки 0';
						$All_Message->Add_Message("Объект 'Приложение'", $str, 0, "Разработчик");
						$All_Message->Add_Message("Объект 'Приложение'", "Ошибка работы сайта. Выполните операцию позже", 0, "Пользователь");
						$ReturnValue = False;
					} else {
						if ($Result['Ошибка'] == True) {
							$ReturnValue = False;
							$All_Message->Add_Message("Объект 'Приложение'", $Result['ОписаниеОшибки'], 0, "Разработчик");
							$All_Message->Add_Message("Объект 'Приложение'", "Ошибка работы сайта. Выполните операцию позже", 0, "Пользователь");
						}
					}
					// Очистка ресурсов
					curl_close($Obj_ch);
					unset($Result, $info);
				}
				unset($ResponseJson, $Obj_ch, $json_data, $data, $Str_hsAdress, $str);

			} else {

				$Str_DBName = "Подтверждение адреса электронной почты";
				if (strlen($S_EMail) == 0 || strlen($S_TextConfirm) == 0)
					$ReturnValue = false;
				else {					//Доработать проверку  существования текста подтверждения и записать логи, в случае некорректного
					$SQL_Query = "SELECT `AdressEMail`, `Confirm`, `ConfirmText`, `ConfirmTextDate"
						. "` FROM `tableemailusers` WHERE `AdressEMail` = '" . $MainConnect->ConnectDB->real_escape_string($S_EMail) . "' AND `ConfirmText` = '" . $S_TextConfirm
						. "' AND `Confirm` = '0'";
					if ($Result = $MainConnect->execSQLQuery($All_Message, $this, $SQL_Query)) {
						if ($Result->num_rows == 0) {
							$Message = "Неудачная попытка подтверждения адреса электронной почты: '" . $S_EMail . "' - '" . $S_TextConfirm . "'";
							$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", 0);
							$MainConnect->insertLogMessage($All_Message, $Message, $this);
							$ReturnValue = false;
						}
						else{							$SQL_Query = "UPDATE `tableemailusers` SET `Confirm` = '1', `ConfirmText` = '', `DateConfirm` = '" . date("Y-m-d H:i:s")
								. "' WHERE `tableemailusers`.`AdressEMail` = '" . $MainConnect->ConnectDB->real_escape_string($S_EMail) . "' AND `tableemailusers`.`ConfirmText` = '" . $S_TextConfirm
								. "' AND `tableemailusers`.`Confirm` = '0'";
							$ReturnValue = $MainConnect->execSQLQuery($All_Message, $this, $SQL_Query);
						}
					}
					else{						$Message = "Ошибка выполнения запроса: '" . $SQL_Query . "' - '" . $MainConnect->error . "'";						$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $MainConnect->errno);
						$MainConnect->insertLogMessage($All_Message, $Message, $this);						$ReturnValue = false;
					}				}
			}

			return $ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getListBaners(Object Connections, Object ErrorOfModul, Array Parameters)
	###		Получить список банеров ресурсов
		public function getListBaners($MainConnect, $All_Message, $Arr_Params) {
	###------- Входные параметры
	###  Object Connections			- объект содержащий сведения о подключении
	###  Object ErrorOfModul		- объект хранения сообщений по системе
	###  Array Arr_Params			- массив параметров
	###------- Выходные параметры
	###  Array 						- массив банеров
	###
			$_ReturnValue = array();

			If ($MainConnect->Boo_Use1CManager == True) {

				$All_Message->Add_Message("Объект 'Приложение'", "Начало получения данных о банерах", 0, "Разработчик");

				$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/ws/PortalMaintenance.1cws?wsdl';

				$_ValueConnection = $MainConnect->setConnection($All_Message);

				$Result = NULL;
				If ($_ValueConnection) {
					Try {
						$JSONData = json_encode($Arr_Params, JSON_UNESCAPED_UNICODE);
						$_paramMethod = array(
								"CodePortal" => Str_PortalIdent,
								"Parameters" => $JSONData
							);

						$HTTPConnection = $MainConnect->ConnectDB;
						$Result = $HTTPConnection->GetBanersInfo($_paramMethod)->return;
					} Catch(Exception $e) {
						$All_Message->Add_Message("Объект 'Приложение'", "Ошибка обращения к методу 'GetBanersInfo()' WEB сервиса '" . $MainConnect->Str_HTTPWSAdress . "'. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
						$MainConnect->insertLogMessage($All_Message ,$e->getMessage());
						//$_ReturnValue = False;
						$Result = NULL;
					}
				}
				$MainConnect->Str_HTTPWSAdress = "";

				If ($Result !== NULL && is_object($Result)) {
					If (isset($Result->Error) && $Result->Error == False) {
						$AnswerService = json_decode($Result->Result, True)['#value'];
						$ArrResult = $AnswerService['ListBanersInfo'];
						$this->N_NumPagesInfo = $AnswerService['NumPagesInfo'];
						If (is_array($ArrResult)) {
			 				$Num_Row = 0;
							Foreach($ArrResult As &$Value) {
								$Obj_Baner = New BanerProperties($Value['SID']);

								$Obj_Baner->_P_ID = $Value['PID'];
								$Obj_Baner->_S_Name = $Value['FullName'];
								$_D_Value = (($Value['DataAdd'] == NULL) ? NULL : date("Y-m-d H:i:s", strtotime($Value['DataAdd'])));
								$Obj_Baner->_D_Add = $_D_Value;
								$Obj_Baner->_S_IDManager = $Value['ManagerSID'];
								$Obj_Baner->_S_Description = $Value['Description'];
								$Obj_Baner->_I_IdentPicture = (int)$Value['IdentPicture'];
								$Obj_Baner->_S_IdentPicture = $Value['PathPicture'];
								$Obj_Baner->_B_Confirm = (bool)$Value['Confirm'];
								$_D_Value = (($Value['DateConfirm'] == NULL) ? NULL : date("Y-m-d H:i:s", strtotime($Value['DateConfirm'])));
								$Obj_Baner->_D_DateConfirm = $_D_Value;
								$Obj_Baner->_B_Blocked = (bool)$Value['Blocked'];
								$_D_Value = (($Value['DateBlock'] == NULL) ? NULL : date("Y-m-d H:i:s", strtotime($Value['DateBlock'])));
								$Obj_Baner->_D_DateBlock = $_D_Value;
								$Obj_Baner->_S_BlockNote = $Value['BlockNote'];
								$Obj_Baner->_S_MotiveBlock = $Value['MotiveBlock'];

								$_Arr_Types = array();
								$_Num_Temp = 0;
								If (isset($Value['ListTypesShort']) && is_array($Value['ListTypesShort'])) {
									Foreach($Value['ListTypesShort'] As &$ValueTemp) {
										$_ArrayTemp = array();
										$_ArrayTemp['ID'] = $ValueTemp['NumStr'];
										$_ArrayTemp['Delete'] = False;
										$_ArrayTemp['PID'] = $ValueTemp['PID'];
										$_ArrayTemp['Object'] = $this->FindTypeBanerBySID($ValueTemp['SID']);
										$_Arr_Types[$_Num_Temp] = $_ArrayTemp;
										$_Num_Temp ++;
										unset($_ArrayTemp);
									}
								}
								$Obj_Baner->setTypes($_Arr_Types);

	 							$Obj_TempType = Null;
	 							If (is_array($Obj_Baner->_Arr_Types) && count($Obj_Baner->_Arr_Types) > 0)
		 							$Obj_TempType = &$Obj_Baner->_Arr_Types[0]['Object'];
	 							$_Obj_Temp = New ImageLink();
								$_Obj_Temp->_B_Review = !$Obj_Baner->_B_Confirm;
								$_Obj_Temp->_B_Blocked = $Obj_Baner->_B_Blocked;
								$_Obj_Temp->_I_IndexImg = $Obj_Baner->_I_IdentPicture;
								$_Obj_Temp->_S_LinkAdress = $Obj_Baner->_S_IdentPicture;
	 							If ($Obj_Baner->_B_Blocked) {
	 								$_Obj_Temp->_B_Template = True;
	 							}
	 							ElseIf (!$Obj_Baner->_B_Confirm) {
	 								$_Obj_Temp->_B_Template = True;
								}
	 							$Obj_Baner->_O_BanerImage = $_Obj_Temp;
								unset($_Obj_Temp);

								$_Arr_HTTP = array();
								$_Num_Temp = 0;
								If (isset($Value['ListHTTPLinks']) && is_array($Value['ListHTTPLinks'])) {
									Foreach($Value['ListHTTPLinks'] As &$ValueTemp) {
										$_ArrayTemp = array();
										$_ArrayTemp['ID'] = $ValueTemp['NumStr'];
										$_ArrayTemp['Delete'] = False;
										$_Obj_Temp = New PageInternetInfo($ValueTemp);
										$_ArrayTemp['Object'] = $_Obj_Temp;
										$_Arr_HTTP[$_Num_Temp] = $_ArrayTemp;
										$_Num_Temp ++;
										unset($_ArrayTemp);
									}
								}
								$Obj_Baner->setHTTPLinks($_Arr_HTTP);

								$_Arr_Adresses = array();
								$_Num_Temp = 0;
								If (isset($Value['ListAdresses']) && is_array($Value['ListAdresses'])) {
									Foreach($Value['ListAdresses'] As &$ValueTemp) {
										$_ArrayTemp = array();
										$_ArrayTemp['ID'] = $ValueTemp['NumStr'];
										if ($ValueTemp['NumStr'] > $Obj_Baner->_I_AdresMaxNumber)
											$Obj_Baner->_I_AdresMaxNumber = $ValueTemp['NumStr'];
										$_ArrayTemp['Delete'] = False;
										//$_Obj_Temp = new PageInternetInfo($ValueTemp);
										$_ArrayTemp['Object'] = $ValueTemp['AdressValue'];
										$_Arr_Adresses[$_Num_Temp] = $_ArrayTemp;
										$_Num_Temp ++;
										unset($_ArrayTemp);
									}
								}
								$Obj_Baner->setRealAdresses($_Arr_Adresses);

								//print_r($Obj_Baner);
								$_ReturnValue[$Num_Row] = $Obj_Baner;

								$Num_Row ++;
								unset($_Num_Temp, $Obj_Baner, $_Arr_Types, $_Arr_HTTP);
							}
							unset($Num_Row);
						} Else {
							$All_Message->Add_Message("Объект 'Приложение'", "Ошибка получения данных о банерах. Некорректные данные ответа", 0, "Разработчик");
						}
						unset($ArrResult);
					} Else {
						$All_Message->Log_GlobalError = True;
						If (isset($Result->ErrorMessage))
							$All_Message->Add_Message("Объект 'Приложение'", $Result->ErrorMessage, 0, "Разработчик");
						$All_Message->Add_Message("Объект 'Приложение'", "Ошибка получения данных о банерах. Ошибка неизвестна", 0, "Разработчик");
					}
				} Else {
					$All_Message->Add_Message("Объект 'Приложение'", "Ошибка получения данных о банерах. Неизвестный ответ сервиса '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
				}

				$All_Message->Add_Message("Объект 'Приложение'", "Завершение получения данных о банерах", 0, "Разработчик");
				unset($_ValueConnection, $Result, $HTTPAdress, $HTTPHeader, $HTTPRequest, $_paramMethod, $JSONData, $data);

			} Else {
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getHTMLTextListTypeBaners(Object Connections, Object ErrorOfModul, Array Parameters)
	###		Получить HTML список типов банеров ресурсов
		public function getHTMLTextListTypeBaners($All_Message, $Arr_Post, $B_ReadOnly = False, $N_CountCols = 3, $N_SizeFont = 18, $FieldPostSelectTypes = "") {
	###------- Входные параметры
	###  Object ErrorOfModul		- объект хранения сообщений по системе
	###  Array Arr_Post				- массив POST параметров страницы
	###  Bool B_ReadOnly			- признак "Только чтение, для вывода элементов
	###  Integer N_CountCols		- количество колонок для формирования списка
	###  Integer N_SizeFont			- размер шрифта для стиля текста
	###  String FieldPostSelectTypes  - имя поля в POST параметрах для выбранных ранее элементов
	###------- Выходные параметры
	###  String 					- HTML текст для вывода текста типов банеров
	###
			$_ReturnValue = "";

		 	$_N_IndexRow = 0;
			$_B_OpenRow = False;
			$_Arr_PostTypes = array();

			If ($FieldPostSelectTypes !== "") {				If (isset($Arr_Post[$FieldPostSelectTypes]) && $Arr_Post[$FieldPostSelectTypes] !== "") {					$_Arr_PostTypes = explode(", ", $Arr_Post[$FieldPostSelectTypes]);				}			}

			If ($B_ReadOnly === False) {
				$_Arr_TypesBaners = &$this->Arr_TypesBaner;
			}
			Else{
		    	$_Arr_TypesBaners = array();
		    	$_Num_Ind = 0;

				Foreach ($this->Arr_TypesBaner As &$Value) {

			    	$_Arr_TypesBanersCh = array();
			    	$_Num_IndCh = 0;
					if (isset($Value['Children']) && count($Value['Children']) > 0) {
						Foreach ($Value['Children'] As &$ValueChild) {
							$_Obj_Type = $ValueChild['Object'];
							If ($_Obj_Baner->IsHaveType($_Obj_Type->getSID()) && !$ValueChild['Delete']) {
								$_Arr_TypesBanersCh[$_Num_IndCh]['Object'] = $ValueChild['Object'];
								$_Num_IndCh ++;
							}
						}
					}

					$_Obj_Type = $Value['Object'];
					If (($_Obj_Baner->IsHaveType($_Obj_Type->getSID()) && !$Value['Delete']) || (count($_Arr_TypesBanersCh) > 0)){
						$_Arr_TypesBaners[$_Num_Ind]['Object'] = $_Obj_Type;
						$_Arr_TypesBaners[$_Num_Ind]['Children'] = $Arr_TypesBanersCh;
						$_Num_Ind ++;
					}
					unset($_Arr_TypesBanersCh, $_Num_IndCh, $_Obj_Type);
				}
				unset($_Num_Ind);
			}

			$_ReturnValue = "<div style=\"width: 600px; float: left; margin: 7px 0px 7px 0px; border-bottom: black solid 1px; overflow: auto; max-height: 250px\">";

			If (is_array($_Arr_TypesBaners))
				Foreach ($_Arr_TypesBaners As &$Value) {
					$_B_NewRow = False;
					If ((($_N_IndexRow / $N_CountCols) - intval($_N_IndexRow / $N_CountCols)) == 0) {
						If ($_B_OpenRow)
							$_ReturnValue .= "</div><br />";
						$_B_NewRow = True;
						$_ReturnValue .= "<div style=\"float: left\">";
						$_B_OpenRow = True;
					}

					$_Obj_Type = &$Value['Object'];
					$_ReturnValue .= "<ul class=\"UlUpTypeSyte\"><input id=\"TypeSytes_" . $_Obj_Type->_P_ID . "\" name=\"TypeSytes_" . $_Obj_Type->_P_ID . "\" class=\"CheckTypeSytes\" type=\"checkbox\" ";

					If (Isset($Arr_Post['TypeSytes_' . $_Obj_Type->_P_ID]))
						$_ReturnValue .= "checked ";
					Elseif (count($_Arr_PostTypes) > 0) {						Foreach ($_Arr_PostTypes as $El_Temp) {							If ($El_Temp === 'TypeSytes_' . $_Obj_Type->_P_ID) {								$_ReturnValue .= "checked ";
								break;							}
						}					}
					Elseif (Isset($_Obj_Baner) && Is_object($_Obj_Baner)){
						If ($_Obj_Baner->IsHaveType($_Obj_Type->getSID()) && !$Value['Delete'])
							$_ReturnValue .= "checked ";
					}

					$_ReturnValue .= "size=\"" . ($N_SizeFont + 6) . "\" title=\"" . $_Obj_Type->_S_Description . "\"><label for=\"TypeSytes_" . $_Obj_Type->_P_ID . "\">" . $_Obj_Type->_S_PublicName . "</label>";

					If (Isset($Value['Children']) && Count($Value['Children']) > 0) {
						Foreach ($Value['Children'] as &$ValueChild) {
							$_Obj_Type = $ValueChild['Object'];
							$_ReturnValue .= "<li class=\"LiDownTypeSyte\"><input id=\"TypeSytes_" . $_Obj_Type->_P_ID . "\" name=\"TypeSytes_" . $_Obj_Type->_P_ID . "\" class=\"CheckTypeSytes\" type=\"checkbox\" ";

							If (Isset($Arr_Post['TypeSytes_' . $_Obj_Type->_P_ID]))
								$_ReturnValue .= "checked ";
							Elseif (count($_Arr_PostTypes) > 0) {
								Foreach ($_Arr_PostTypes as $El_Temp) {
									If ($El_Temp === 'TypeSytes_' . $_Obj_Type->_P_ID) {
										$_ReturnValue .= "checked ";
										break;
									}
								}
							}
							Elseif (Isset($_Obj_Baner) && Is_object($_Obj_Baner)){
								If ($_Obj_Baner->IsHaveType($_Obj_Type->getSID()) && !$Value['Delete'])
									$_ReturnValue .= "checked ";
							}

							$_ReturnValue .= "size=\"" . $N_SizeFont . "\" title=\"" . $_Obj_Type->_S_Description . "\"><label for=\"TypeSytes_" . $_Obj_Type->_P_ID . "\">" . $_Obj_Type->_S_PublicName . "</label></li>";
						}
					}

					$_ReturnValue .= "</ul>";
					$_N_IndexRow++;
				}

			If ($_B_OpenRow)
				$_ReturnValue .= "</div>";
			$_ReturnValue .= "</div>";

			unset($_Arr_TypesBaners, $_N_IndexRow, $_Obj_Type);

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getHTMLTextListPages(Object ErrorOfModul, Array Parameters, String AdresPage)
	###		Получить HTML список ссылок нумераций страниц
		public function getHTMLTextListPages($All_Message, &$Arr_Get, $Str_AdresPage) {
	###------- Входные параметры
	###  Object ErrorOfModul		- объект хранения сообщений по системе
	###  Array Arr_Get				- массив GET параметров
	###------- Выходные параметры
	###  String 					- HTML текст для вывода текста типов банеров
	###
			$_ReturnValue = "";

			$_ReturnValue = "<div>";

			$Ind = 0;
			$_Arr_AdressRaw = array();
			If (is_array($Arr_Get))
				Foreach ($Arr_Get As $Param => $Value) {
					If ($Param !== 'RoleConnect') {
						$_Arr_AdressRaw[$Ind]['Параметр'] = $Param;
						$_Arr_AdressRaw[$Ind]['Значение'] = $Value;
						$Ind ++;
					}
				}
			$_BeginNum = 0;
			$_LastNum = $this->N_NumPagesInfo - 1;

			If ($this->N_NumPage > ($this->N_StepPages + 1)) {				$_BeginNum = $this->N_NumPage - $this->N_StepPages;			}
			If ($_LastNum > ($this->N_NumPage + $this->N_StepPages)) {				$_LastNum = $this->N_NumPage + $this->N_StepPages;			}

			If ($_BeginNum > 0) {				$_ReturnValue .= "<a href=\"" . $Str_AdresPage . "" . getNewGetForAdresStroka($Arr_Get) . "\">\<\<</a> <a href=\"#\">\<</a> ";
			}

			For ($i = $_BeginNum; $i <= $_LastNum; $i++) {				$_ArrayForGet = $_Arr_AdressRaw;
				$Ind = 0;
				$ElFoud = False;
				Foreach ($_ArrayForGet As $Param => $Value) {
					If ($Value['Параметр'] === "PageContent") {
						$_ArrayForGet[$Param]['Значение'] = $i;
						$ElFoud = True;
					}
					$Ind ++;
				}
				If (!$ElFoud) {
					$_ArrayForGet[$Ind]['Параметр'] = "PageContent";
					$_ArrayForGet[$Ind]['Значение'] = $i;
				}
				If ($this->N_NumPage === $i)
					$_ReturnValue .= " " . ($i + 1) . " ";
				Else
					$_ReturnValue .= "<a href=\"" . $Str_AdresPage . getNewGetForAdresStroka($_ArrayForGet) . "\">" . ($i + 1) . "</a> ";
			}

			If (($_LastNum + 1) < $this->N_NumPagesInfo) {
				$_ReturnValue .= " <a href=\"" . $Str_AdresPage . getNewGetForAdresStroka($Arr_Get) . "\">\>\></a> <a href=\"#\">\></a> ";
			}

			$_ReturnValue .= "</div>";
			//$_ReturnValue = "<div>Текущая страница № " . $this->N_NumPage . " из общего количества страниц " . $this->N_NumPagesInfo . "</div>";

			unset($_BeginNum, $_LastNum);

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### updateServices(Object Connection, Object ErrorOfModul, Array Arr_Data)
	###		- инициировать выполнение метода сервиса обслуживания
		Function updateServices($MainConnect, $All_Message, $Arr_Data) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array Arr_Data				- массив параметров для отправки подтверждения на адрес электронной почты
	###------- Выходные параметры
	###  Bool 	- признак удачной операции по отправке подтверждения на адрес электронной почты
	###

			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {
				// выполнение из приложения 1С
				$_ReturnValue = $this->updateData1CMethod($MainConnect, $All_Message, $Arr_Data);
			} Else {
				// выполнение внутренними методами
	        	$_ReturnValue = $this->updateDataPHPMethod($MainConnect, $All_Message, $Arr_Data);
			}

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

/*
	###@@@@@@@@@@@@@@@@@@@@@
	### insertLogMessage(Object ErrorOfModul, String Message)
	### 	записать сообщения в журнл логов и в объект "Сообщения"
		public function insertLogMessage($All_Message, $Message) {
	###------- Входные параметры
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  String Message				- срока с сообщением
	###------- Выходные параметры
	###  Bool 	- признак выполненной функции
	###
			$S_LogFile = "";
			$Str_DBName = "";
			// Формируем имя файла логов
			if ((isset($this->B_UseValueBD) && $this->B_UseValueBD === True) &&
					(isset($this->S_PathFileLogs) && strlen($this->S_PathFileLogs) <> 0) &&
					(isset($this->S_NameFileLogs) && strlen($this->S_NameFileLogs) <> 0))
				$S_LogFile = $this->S_PathFileLogs . $this->S_NameFileLogs;
			else
				$S_LogFile = Str_PathFileLogs . Str_NameFileLogs;
			if ((isset($this->B_UseValueBD) && $this->B_UseValueBD === True) &&
					(isset($this->S_SystemName) && strlen($this->S_SystemName) <> 0))
				$Str_DBName = $this->S_SystemName;
			else
				$Str_DBName = Str_DBName;

			// записываю сообщение в файл логов и в сообщения разработчику
			try {
				@$Handler = fopen($S_LogFile, "ab");													// Открыть файл для записи в конец файла, если файла нет то создать
				if ($Handler) {																			// Если файл открыт
					if (@flock($Handler, LOCK_EX)) {
						$Str_Forward = "";
						//$_SERVER['HTTP_X_FORWARDED_FOR'];												// Адрес прокси сервера клиента
						$Str_IP = $_SERVER['REMOTE_ADDR'];												// Адрес клиента
						if (($Str_Forward != NULL) && ($Str_Forward != $Str_IP))
							$Str_IP = $Str_IP."/".$Str_Forward;											// Если прокси и адрес клиента не совпадают и прокси существует то добавить к ip адресу клиента прокси адрес
						try {
							$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик");
							@$NkB = fwrite($Handler, date("d.m.y - H:i - ") . $Message .
								"! IP: " . $Str_IP . ".\n");											// Записать в файл ошибки с указанием даты записи, времени и ip адреса клиента
							if ($NkB == 0)																// Если запись не удалась
								throw new FWException($Message.". Не возможно записать в файл!");		// Вызвать обработчик, для обработки ошибки записи в файл
						}
						catch (FWException $e){															// Обработчик ошибки записи в файл
							$All_Message->Log_GlobalError = true;
							$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $e->getCode(), $e->getFile(), $e->getLine());
						}
				    	@flock($Handler, LOCK_UN);
			    	}
					@fclose($Handler);																	// Закрыть файл
					unset($Str_IP, $Str_Forward, $NkB);
				}
				else
					throw new FOException($Message . ". Не возможно открыть файл!");					// Вызвать обработчик ошибки открытия файла
			}
			catch (FOException $e) {																	// Обработчик ошибки открытия файла
				$All_Message->Log_GlobalError = true;
				$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $e->getCode(), $e->getFile(), $e->getLine());
			}
			if (isset($e))
				unset($e);
			if (isset($Handler))
				unset($Handler);
			unset($S_LogFile, $Str_DBName);
		}
	###@@@@@@@@@@@@@@@@@@@@@
*/
	###////// Внутренние

	###@@@@@@@@@@@@@@@@@@@@@
	### FindTypeBanerRecurse(String SID)
	### Получить ссылку на тип банера рекурсивная функция
		private function FindTypeBanerRecurse(&$ArrTypesBaner, $SID) {
	###------- Входные параметры
	###  Link Array 		- ссылка на массив типов банеров
	###  String SID			- код типа банера для поиска
	###------- Выходные параметры
	###  Link BanerType		- ссылка на тип банера
	###
			$_ReturnValue = Null;
/*
Array ( [0] => Array ( [Object] => BanerType Object (
							[_P_ID] =>
							[_S_ID:protected] => 000000002
							[_S_Parent:protected] =>
							[_S_PublicName:protected] => Информация
							[_S_ImageNum:protected] =>
							[_S_Description:protected] => )
						[Children] => Array ( 	[0] => Array ( 	[Object] => BanerType Object (
																	[_P_ID] =>
																	[_S_ID:protected] => 000000001
																	[_S_Parent:protected] => 000000002
																	[_S_PublicName:protected] => Новости
																	[_S_ImageNum:protected] =>
																	[_S_Description:protected] => ) )
												[1] => Array ( [Object] => BanerType Object (
																	[_P_ID] =>
																	[_S_ID:protected] => 000000003
																	[_S_Parent:protected] => 000000002
																	[_S_PublicName:protected] => Поисковый портал
																	[_S_ImageNum:protected] =>
																	[_S_Description:protected] => )
															)
											)
						 )
		 )
Array ( [0] => Array ( [Object] => BanerType Object ( [_P_ID] => [_S_ID:protected] => 000000002 [_S_Parent:protected] => [_S_PublicName:protected] => Информация [_S_ImageNum:protected] => [_S_Description:protected] => ) [Children] => Array ( [0] => Array ( [Object] => BanerType Object ( [_P_ID] => [_S_ID:protected] => 000000001 [_S_Parent:protected] => 000000002 [_S_PublicName:protected] => Новости [_S_ImageNum:protected] => [_S_Description:protected] => ) ) [1] => Array ( [Object] => BanerType Object ( [_P_ID] => [_S_ID:protected] => 000000003 [_S_Parent:protected] => 000000002 [_S_PublicName:protected] => Поисковый портал [_S_ImageNum:protected] => [_S_Description:protected] => ) ) ) ) )

*/
			if (strlen($SID) > 0) {

				Foreach($ArrTypesBaner As &$Value) {

					if ($Value['Object']->getSID() == $SID) {
						$_ReturnValue = &$Value['Object'];
					} elseif (is_array($Value['Children']) && count($Value['Children']) > 0) {
						$_ReturnValue = $this->FindTypeBanerRecurse($Value['Children'], $SID);
					}

					if($_ReturnValue !== Null) {
						break;
					}
				}

			}

			return $_ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readTermsOfUseFromBaseHTTPMethod(Object Connections, Object ErrorOfModul)
	### 	прочитать текст правил использования HTTP методом
		private function readTermsOfUseFromBaseHTTPMethod(Connections $MainConnect, ErrorOfModul $All_Message) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Boolean - признак успешно завершенной операции
	###

			$ReturnValue = False;

			//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
			//	http://noutpc/ManagerPortals/hs/PortalMaintenanceService/PortalInfo/ROP00000000000000002/
			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/PortalMaintenanceService/TermsOfUse/' . Str_PortalIdent . '/';
			$HTTPHeader = array('Content-Length: 0',
							'Content-Language: ru-RU');
			$HTTPRequest = "GET";

			$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest);

			If (is_array($Result) && array_key_exists('Ошибка', $Result) && (bool)$Result['Ошибка'] !== True) {

				$ArrResult = Null;
				If (isset($Result['Результат']))
					$ArrResult = $Result['Результат'];

				If (is_array($ArrResult)) {

					$ReturnValue = True;

					Foreach($ArrResult As $Value) {
						$Argument = $Value['Наименование'];
						$ValueArg = $Value['Значение'];

						$this->setValueClassVar($Argument, $ValueArg);
					}

					unset($Argument, $ValueArg);

				} ElseIf (!is_bool($Result)) {
					If (is_array($Result)) {
						If (array_key_exists('ОписаниеОшибки', $Result))
							$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 0, "Разработчик");
						If ((bool)$Result['ДляПользователя'] == True)
							$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 0, "Пользователь");
					}
					$All_Message->Add_Message("Приложение", "Ошибка метода '" . $HTTPRequest . "' обработки свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'.", 0, "Разработчик");
				} Else
					$ReturnValue = $Result;
				unset($ArrResult);
			} ElseIf (!is_bool($Result)) {
				If (is_array($Result)) {
					If (array_key_exists('ОписаниеОшибки', $Result))
					$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 2, "Разработчик");
					If ((bool)$Result['ДляПользователя'] == True)
						$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 2, "Пользователь");
				}
				$All_Message->Add_Message("Приложение", "Ошибка сервиса при обработке свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'", 2, "Разработчик");
			} Else
				$ReturnValue = $Result;

			$MainConnect->Str_HTTPWSAdress = "";

			unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest);

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readPolicySecurityFromBaseHTTPMethod(Object Connections, Object ErrorOfModul)
	### 	прочитать текст политики безопасности HTTP методом
		private function readPolicySecurityFromBaseHTTPMethod(Connections $MainConnect, ErrorOfModul $All_Message) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Boolean - признак успешно завершенной операции
	###

			$ReturnValue = False;

			//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
			//	http://noutpc/ManagerPortals/hs/PortalMaintenanceService/PortalInfo/ROP00000000000000002/
			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/PortalMaintenanceService/PolicySecurity/' . Str_PortalIdent . '/';
			$HTTPHeader = array('Content-Length: 0',
							'Content-Language: ru-RU');
			$HTTPRequest = "GET";

			$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest);

			If (is_array($Result) && array_key_exists('Ошибка', $Result) && (bool)$Result['Ошибка'] !== True) {

				$ArrResult = Null;
				If (isset($Result['Результат']))
					$ArrResult = $Result['Результат'];

				If (is_array($ArrResult)) {

					$ReturnValue = True;

					Foreach($ArrResult As $Value) {
						$Argument = $Value['Наименование'];
						$ValueArg = $Value['Значение'];

						$this->setValueClassVar($Argument, $ValueArg);
					}

					unset($Argument, $ValueArg);

				} ElseIf (!is_bool($Result)) {
					If (is_array($Result)) {
						If (array_key_exists('ОписаниеОшибки', $Result))
							$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 0, "Разработчик");
						If ((bool)$Result['ДляПользователя'] == True)
							$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 0, "Пользователь");
					}
					$All_Message->Add_Message("Приложение", "Ошибка метода '" . $HTTPRequest . "' обработки свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'.", 0, "Разработчик");
				} Else
					$ReturnValue = $Result;
				unset($ArrResult);
			} ElseIf (!is_bool($Result)) {
				If (is_array($Result)) {
					If (array_key_exists('ОписаниеОшибки', $Result))
					$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 2, "Разработчик");
					If ((bool)$Result['ДляПользователя'] == True)
						$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 2, "Пользователь");
				}
				$All_Message->Add_Message("Приложение", "Ошибка сервиса при обработке свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'", 2, "Разработчик");
			} Else
				$ReturnValue = $Result;

			$MainConnect->Str_HTTPWSAdress = "";

			unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest);

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### CorrectProperty(Array SessionArray)
	### 	Дополнить данные временного массива Сессии
		private function CorrectProperty($Arr_Sess) {
			If (!$this->B_ControlIP)
				$Arr_Sess['S_OldIPUser'] = "";
			If (!$this->B_ControlClient)
				$Arr_Sess['S_OldClient'] = "";
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Установка значений класса
	### setValueClassVar(String Argument, Void Value)
	### 	Инициализация установки переменных класса
		private function setValueClassVar($Argument, $Value) {
	###------- Входные параметры
	###  String Argument		- Наименование полученной переменной из таблиц настроек
	###  Void Value				- Значение переменной
	###------- Выходные параметры
	###  ----
	###

			switch ($Argument) {
				case "Наименование сайта":
					$this->S_SiteName = $Value;
					break;
				case "Наименование системы":
					$this->S_SystemName = $Value;
					break;
				case "Краткое описание":
					$this->S_Description = $Value;
					break;
				case "Описание":
					$this->S_About = $Value;
					break;
				case "Поисковый контент":
					$this->S_FindContent = $Value;
					break;
				case "Использовать E-Mail":
					$this->Arr_EMail["Use"] = $Value;
					break;
				case "Адрес E-Mail сервера":
					$this->Arr_EMail["Server"] = $Value;
					break;
				case "SMTP сервер":
					$this->Arr_EMail["SMTP"] = $Value;
					break;
				case "Port SMTP сервера":
					$this->Arr_EMail["SMTPPort"] = $Value;
					break;
				case "Socket SMTP сервера":
					$this->Arr_EMail["SMTPSocket"] = $Value;
					break;
				case "SMTP использует пароль":
					$this->Arr_EMail["SMTPNeedPass"] = $Value;
					break;
				case "Логин SMTP сервера":
					$this->Arr_EMail["SMTPLogin"] = $Value;
					break;
				case "Пароль SMTP сервера":
					$this->Arr_EMail["SMTPPassword"] = $Value;
					break;
				case "Админ E-Mail":
					$this->Arr_EMail["Admin"] = $Value;
					break;
				case "Модератор E-Mail":
					$this->Arr_EMail["Moderator"] = $Value;
					break;
				case "Разработчик Е-Mail":
					$this->Arr_EMail["Developer"] = $Value;
					break;
				case "Робот E-Mail":
					$this->Arr_EMail["Robot"] = $Value;
					break;
				case "Инфо E-Mail":
					$this->S_EmailContact = $Value;
					break;
				case "Техподдержка E-Mai":
					$this->S_EmailTechService = $Value;
					break;
				case "Инфо телефон":
					$this->S_TelefonContact = $Value;
					break;
				case "Техподдержка телефон":
					$this->S_TelefonTechService = $Value;
					break;
				case "Есть конфиденциальные данные":
					$this->B_UseConfData = $Value;
					break;
				case "Есть новости":
					$this->B_UseNews = $Value;
					break;
				case "Использовать счетчик":
					$this->Arr_Counter["Use"] = $Value;
					break;
				case "Имя БД счетчика":
					$this->Arr_Counter["Name"] = $Value;
					break;
				case "Тип БД счетчика":
					$this->Arr_Counter["Type"] = $Value;
					break;
				case "Host подключения счетчика":
					$this->Arr_Counter["HostName"] = $Value;
					break;
				case "IP подключения счетчика":
					$this->Arr_Counter["IP"] = $Value;
					break;
				case "Порт подключения счетчика":
					$this->Arr_Counter["Port"] = $Value;
					break;
				case "Сокет подключения счетчика":
					$this->Arr_Counter["Socket"] = $Value;
					break;
				case "Логин счетчика":
					$this->Arr_Counter["Login"] = $Value;
					break;
				case "Пароль счетчика":
					$this->Arr_Counter["Password"] = $Value;
					break;
				case "Путь временных":
					$this->S_PathFileTemp = $Value;
					break;
				case "Путь логов":
					$this->S_PathFileLogs = $Value;
					break;
				case "Имя файла логов":
					$this->S_NameFileLogs = $Value;
					break;
				case "Путь начального":
					$this->S_PathFileBegin = $Value;
					break;
				case "Файл запуска":
					$this->S_FileBegin = $Value;
					break;
				case "Путь подключаемых":
					$this->S_IncludeDir = $Value;
					break;
				case "Путь картинок":
					$this->S_PictureDir = $Value;
					break;
				case "Авторское право":
					$this->S_Autor = $Value;
					break;
				case "Дизайнер":
					$this->S_Designer = $Value;
					break;
				case "Разработчик":
					$this->S_Developer = $Value;
					break;
				case "Использовать вход в систему":
					$this->B_UseUserAccount = $Value;
					break;
				case "Использовать настройки БД":
					$this->B_UseValueBD = $Value;
					break;
				case "Использовать Coockies":
					$this->B_UseCoockies = $Value;
					break;
				case "Использовать Flash":
					$this->B_UseFlash = $Value;
					break;
				case "Версия":
					$this->S_Version = $Value;
					break;
				case "Дата версии":
					$this->D_DateVersion = $Value;
					break;
				case "Контроль IP":
					$this->B_ControlIP = $Value;
					break;
				case "Контроль клиента":
					$this->B_ControlClient = $Value;
					break;
				case "Движок. Показывать инфо":
					$this->B_EngineShow = $Value;
					break;
				case "Движок. Наименование":
					$this->S_EngineName = $Value;
					break;
				case "Движок. Версия":
					$this->S_EngineVersion = $Value;
					break;
				case "Движок. Дата версии":
					$this->D_EngineDataVersion = $Value;
					break;
				case "Правила. Дата версии":
					$this->D_DateTermsOfUse = $Value;
					break;
				case "Правила. Заголовок":
					$this->S_HeaderTermsOfUse = $Value;
					break;
				case "Правила. Текст":
					$this->S_TextTermsOfUse = $Value;
					break;
				case "Политика. Дата версии":
					$this->D_DatePolicySecurity = $Value;
					break;
				case "Политика. Заголовок":
					$this->S_HeaderPolicySecurity = $Value;
					break;
				case "Политика. Текст":
					$this->S_TextPolicySecurity = $Value;
					break;
				case "Метрика. Яндекс":
					$this->B_UseYandexMetriks = $Value;
					break;
				case "Метрика. Текст Яндекс":
					$this->S_YandexMetriks = $Value;
					break;
				case "Метрика. Гугл":
					$this->B_UseGoogleMetriks = $Value;
					break;
				case "Метрика. Текст Гугл":
					$this->S_GoogleMetriks = $Value;
					break;
				case "Портал. Основное меню":
					$this->Arr_Menu = $Value;
					break;
				case "Портал. Массив страниц":
					$this->Arr_Pages = $Value;
					break;
			}
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### saveConfig(Object Connections, Object ErrorOfModul)
	###										:Bool		- Сохранить данные объекта в базу данных
		private function saveConfig($MainConnect, $All_Message, $DataArray) {

			$RetunResult = True;
			$Str_DBName = "Сохранение параметров сайта";
			If ($MainConnect->Boo_Use1CManager == True) {
				$Message = "Редактирование реквизитов сайта/системы, предусмотрено через дополнительный интерфейс";
				$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик");
				$MainConnect->insertLogMessage($All_Message, $Message, $this);
				$RetunResult = False;
				unset($Message);
			} Else {

/*
		UPDATE `managerbaners`.`cfgtable` SET `Value` = 'Шаблон динамического интернет сайта'
			WHERE `cfgtable`.`ArgumentName` = 'Наименование системы';
		UPDATE `managerbaners`.`cfgtable` SET `Value` = 'RusColor'
			WHERE `cfgtable`.`ArgumentName` = 'Наименование сайта';
*/
			// Формирование SQL запроса для обновления данных в таблице настроек
				$SQL_Query = "";

				Foreach($this->B_NS as $Key => $Value) {					If ($Value["Value"] !== $DataArray[$Key]["Value"]) {						If (is_string($DataArray[$Key]["Value"]))
							$SaveValue = addslashes($DataArray[$Key]["Value"]);
						Else
							$SaveValue = $DataArray[$Key]["Value"];
						$SQL_Query .= "UPDATE `managerbaners`.`cfgtable` SET `Value` = '" . $SaveValue . "' WHERE `cfgtable`.`ArgumentName` = '" . $Key . "';";					}
				}

				$MainConnect->SQLQuery = $SQL_Query;
				If ($MainConnect->execSQLQuery($All_Message, $this, "", True))
					$RetunResult = True;
				Else
					$RetunResult = False;
			}
			unset($Str_DBName);
			return $RetunResult;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### updateData1CMethod(Object Connection, Object ErrorOfModul, Array Arr_Data)
	###		- выполнить метод сервиса обслуживания порталов сервисными службами методом HTTP 1С
		Private Function updateData1CMethod($MainConnect, $All_Message, $Arr_Data) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array Arr_Data				- массив параметров
	###------- Выходные параметры
	###  Bool 	- признак удачной операции
	###

			$_ReturnValue = False;

			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/PortalMaintenanceService/PortalServices/' . Str_PortalIdent;

			$JSONData = json_encode($Arr_Data, JSON_UNESCAPED_UNICODE);

			$HTTPRequest = "POST";
			$HTTPHeader = array('Content-Type: application/json',
							'Content-Language: ru-RU');

			$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest, $JSONData);

			If (is_array($Result) && array_key_exists('Ошибка', $Result) && (bool)$Result['Ошибка'] !== True) {

				$_ReturnValue = True;
				$ArrResult = $Result['Результат'];
				If (is_array($ArrResult)) {
					Foreach($ArrResult As $Value) {
/*
						$Argument = $Value['Наименование'];
						$ValueArg = $Value['Значение'];
						$this->setValueClassVar($Argument, $ValueArg);
*/
					}
					unset($Argument, $ValueArg);
				}
				unset($ArrResult);
			} ElseIf (!is_bool($Result)) {
				If (is_array($Result)) {
					If (array_key_exists('ОписаниеОшибки', $Result))
						$All_Message->Add_Message("Приложение", $Result['ОписаниеОшибки'], 2, "Разработчик");
					If ((bool)$Result['ДляПользователя'] == True)
						$All_Message->Add_Message("Приложение", $Result['ТекстПользователю'], 2, "Пользователь");
				}
				$All_Message->Add_Message("Приложение", "Ошибка сервиса при обработке свойств портала '" . $MainConnect->Str_HTTPWSAdress . "'", 2, "Разработчик");
			} Else
				$_ReturnValue = $Result;

			$MainConnect->Str_HTTPWSAdress = "";

			unset($Result, $HTTPHeader, $HTTPRequest, $JSONData, $data);

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### updateDataPHPMethod(Object Connection, Object ErrorOfModul, Array Arr_Data)
	###		- выполнить метод сервиса обслуживания порталов сервисными службами внутренним методом
		Private Function updateDataPHPMethod($MainConnect, $All_Message, $Arr_Data) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array Arr_Data				- массив параметров
	###------- Выходные параметры
	###  Bool 	- признак удачной операции
	###

			$_ReturnValue = False;

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

	////////////////////////////////////////////////////

	}
	######      Конец описания объекта             #####
	####################################################
?>
