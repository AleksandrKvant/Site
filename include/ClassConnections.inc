<?php
	####################################################
	########       Объект  "Соединение"           ######
	####################################################
	class Connections{
	### Наименование - Connections
 	###  	Объект для реализации соединения с БД
    ###
    ###-------------------------------------------------
    ###  Требуются объекты для работы
    ### ErrorOfModul All_Message		// Объект "Сообщения системы"
	////////////////////////////////////////////////////
 	################    Свойства    ####################
	////////////////////////////////////////////////////
 	###////// Открытые
	###
 	###------------------------------------------------
  	###////// Защищенные
	###	ConnectDB		:Mysqli			// Соединение с БД
  	### SQLQuery		:String			// Запрос на исполнение
  	### Str_HTTPWSAdress;	:String		// Адресс сервиса в сети
	###
 	###------------------------------------------------
  	###////// Закрытые
	###	Str_DBName			:String			// Имя БД
	###	Str_DBType			:String			// Тип БД
	###	Str_HostName		:String			// Имя хоста
	###	Str_HostIP			:String			// IP адрес хоста
	###	Int_Port			:Integer		// Порт адрес хоста
	###	Str_Socket			:String			// Сокет адрес хоста
	###	Str_AccountName		:String			// Акк для работы с БД
	### Str_AccountPass		:String			// Пароль от Акк для работы с БД
	### Boo_Use1CManager	:Boolean		// Признак использования приложения 1С
	### Boo_HTTPServices	:Boolean		// Признак использования HTTP сервисов для приложения 1С
	### Boo_UseProtectConnect	:Boolean		// Признак использования защищенного соединения
	###
 	###------------------------------------------------
	###////// Требующие реализации
	###
	////////////////////////////////////////////////////
	###########   Методы класса   ######################
	////////////////////////////////////////////////////
	###////// Открытые
	###
	###  __construct()							:Oblect		- Конструктор объекта класса
	###  __set(String Name_Var, Void _Value_Var):Void		- Установить значение свойства класса
	###  __get(String Name_Var)					:Void		- Прочитать значение своства класса
	### setConnection(Object ErrorOfModul)		:Bool		- Установить cоединение к БД или WEB сервисам по установленным параметрам в объекте. Если параметры не установлены или соединение не удачно - вернет False
	###
	### execHTTPMetod(Object ErrorOfModul, String HTTPHeader, String HTTPRequest, Array Data)
	### 										:Array 		- Выполнение HTTP запроса
	### getIDRecord(Object ErrorOfModul, String TableSinonim, Void Znachenie)
	### 										:Void		- вычислить ID записи для указанной таблицы в БД
	### matchNewIDRecord(Object ErrorOfModul, String TableName, Bool UseAllNumber)
	### 										:Void		- вычислить новый ID для указанной таблицы в БД у текущего соединения, указанного в этом объекте
	### execSQLQuery()								:Void		- Выполнить запрос. Вернет результат запросв или False, если неудачное выполнение запроса
	### execHTTPMetod()
	###
	###////// Закрытые
	###
	### FindTableName(String TableSinonim)
	### 										:String		- найти имя таблицы в БД
	### matchNewID(Object ErrorOfModul, Void OldMaxNum)
	###											:Void		- вычисление нового ID
	### insertLogMessage(Object ErrorOfModul, String Message)
	###											:Bool		- записать ошибки в файлы и в объект "собщения"
	###
	////////////////////////////////////////////////////
	##########       Свойства класса       #############
	////////////////////////////////////////////////////
 	### Открытые
 	### Защищенные
		protected $ConnectDB;			//Mysqli	- Соединение с БД
		protected $SQLQuery;			//String	- Запрос на исполнение
		protected $Str_HTTPWSAdress;	//String	- Адресс сервиса в сети
 	### Закрытые
		private $Str_DBName;			//String	- Имя БД
		private $Str_DBType;            //String	- Тип БД
		private $Str_HostName;          //String	- Имя хоста
		private $Str_HostIP;            //String	- IP адрес хоста
		private $Int_Port;           	//Integer	- Порт хоста
		private $Str_Socket;            //String	- Сокет хоста
		private $Str_AccountName;       //String	- Акк для работы с БД
		private $Str_AccountPass;       //String	- Пароль от Акк для работы с БД
		private $Boo_Use1CManager;		//Boolean	- Признак использования приложения 1С
		private $Boo_HTTPServices;		//Boolean	- Признак использования HTTP сервисов для приложения 1С
		private $Boo_UseProtectConnect;	//Boolean	- Признак использования защищенного соединения

	////////////////////////////////////////////////////
	##########        Методы класса        #############
	////////////////////////////////////////////////////

	###////// Открытые

    ###@@@@@@@@@@@@@@@@@@@@@
	###  Конструктор класса
	### __construct()
	### 	Создание объекта класса
		public function __construct(){
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  Object - объект типа Connection
	###
		$this->ConnectDB = NULL;			//:Object	- соединение с БД
		$this->Str_DBName = "";				//:String	- Имя БД
		$this->Str_DBType = "";				//:String	- Тип БД
		$this->Str_HostName = "";			//:String	- Имя хоста
		$this->Str_HostIP = "";				//:String	- IP адрес хоста
		$this->Int_Port = 0;	  	     	//:Integer	- Порт хоста
		$this->Str_Socket = "";				//:String	- Сокет хоста
		$this->Str_AccountName = "";		//:String	- Акк для работы с БД
		$this->Boo_Use1CManager = false;		//:Boolean	- Признак использования приложения 1С
		$this->Boo_HTTPServices = false;		//:Boolean	- Признак использования HTTP сервисов для приложения 1С
		$this->Boo_UseProtectConnect = false;	//:Boolean	- Признак использования защищенного соединения
		$Str_HTTPWSAdress = "";
	}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Установка значений класса
	### __set(String Name_Var, Void _Value_Var)
	### 	Конструктор класса
		public function __set($_Name_Var, $_Value_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###  Void _Value_Var			- Значение переменной
	###------- Выходные параметры
	###
			if ($_Name_Var != "ConnectDB")
				$this->$_Name_Var = $_Value_Var;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Считывание значений свойств класса
	### __get(String Name_Var)
	### 	Конструктор класса
		public function __get($_Name_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###------- Выходные параметры
	###  Void _Value_Var			- Значение переменной
	###
			$ReturnValue = false;
			if ($_Name_Var != "_S_ID")
				$ReturnValue = $this->$_Name_Var;

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

 	###@@@@@@@@@@@@@@@@@@@@@
	### execHTTPMetod(Object ErrorOfModul, String HTTPHeader, String HTTPRequest, Array Data)
	### 	выполнение HTTP запроса к сервисам
		public function execHTTPMetod(ErrorOfModul $All_Message, $HTTPHeader, $HTTPRequest, $JSONData = NULL) {
	###------- Входные параметры
	###  Object ErrorOfModul			- Объект хранения сообщений по системе
	###  Array HTTPHeader				- массив заголовка HTTP запроса
	###  String HTTPRequest				- строка - тип HTTP запроса
	###  JSON JSONData					- строка данных в формате JSON
	###------- Выходные параметры
	###  Массив - массив данных полученных при обращении к HTTP сервису
	###

			$_ResultValue = Null;
			//Получение файла JSON используя curl
			//Инициализация
			$Obj_ch = curl_init(Str_HostName . '/' . Str_DBName . '/');

			// Заполняем параметры CURL для получения данных по HTTP запросу
			curl_setopt($Obj_ch, CURLOPT_HTTPHEADER, $HTTPHeader);
			curl_setopt($Obj_ch, CURLOPT_URL, $this->Str_HTTPWSAdress);
			curl_setopt($Obj_ch, CURLOPT_CUSTOMREQUEST, $HTTPRequest);
			curl_setopt($Obj_ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
			//curl_setopt($Obj_ch, CURLOPT_HTTPHEADER, array('Content-Length: 0'));                 // для пустого запроса
			//curl_setopt($Obj_ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json'));	// для передачи параметров
			curl_setopt($Obj_ch, CURLOPT_USERPWD, $this->Str_AccountName . ":" . $this->Str_AccountPass);
			//curl_setopt($Obj_ch, CURLOPT_FOLLOWLOCATION, True);
			curl_setopt($Obj_ch, CURLOPT_RETURNTRANSFER, True);
			curl_setopt($Obj_ch, CURLOPT_SSL_VERIFYPEER, False);
			curl_setopt($Obj_ch, CURLOPT_CONNECTTIMEOUT, 2);
			curl_setopt($Obj_ch, CURLOPT_TIMEOUT, 3);
			If ($JSONData !== NULL) {
				curl_setopt($Obj_ch, CURLOPT_POSTFIELDS, $JSONData);								// передача параметров
				If ($HTTPRequest !== "GET")
					curl_setopt($Obj_ch, CURLOPT_POST, 1);												// инициализация POST запроса
			}

			// Выполнение запроса и получение ответа
			try {
				$ResponseJson = curl_exec($Obj_ch);
			} catch (Exception $e) {				$All_Message->Add_Message("Объект 'Соединение'", "Ошибка обращения к методу '" . $HTTPRequest . "', WEB сервиса '" . $this->Str_HTTPWSAdress . "'. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
				$_ReturnValue = False;
				$ResponseJson = False;
			}

			// Проверка наличия ошибок
			if ($ResponseJson === False) {

				$str = 'Ошибка выполнения запроса ' . curl_error($Obj_ch) . ' для сервиса ' . $this->Str_HTTPWSAdress;
				$All_Message->Add_Message("Объект 'Соединение'", $str, 0, "Разработчик");
				$All_Message->Log_GlobalError = True;

			} else {

				//Выводим сервисную информацию по выполнению запроса
				$info = curl_getinfo($Obj_ch);
				$str = 'Время выполнения запроса ' . $info['total_time'] . ' секунд для сервиса ' . $info['url'];
				$All_Message->Add_Message("Объект 'Соединение;", $str, 0, "Разработчик");

				// Очистка ресурсов
				curl_close($Obj_ch);

				$_ResultValue = json_decode($ResponseJson, true);
				If ($_ResultValue === Null) {
					$_ResultValue = False;
					$str = 'Ошибка выполнения запроса "' . $HTTPRequest . '"для сервиса ' . $info['url'];
					$All_Message->Add_Message("Объект 'Соединение'", $str, 0, "Разработчик");
					$All_Message->Log_GlobalError = True;
				}

			}

			unset($ResponseJson, $Obj_ch, $str, $info);

			return $_ResultValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setConnection(Object ErrorOfModul)
	### 	установить cоединение к БД или WEB сервисам по установленным параметрам в объекте. Если параметры не установлены или соединение не удачно - вернет False
		public function setConnection($All_Message){
	###------- Входные параметры
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Bool - признак удачной установки соединения к БД
	###
			$ReturnValue = True;

            if ($this->Boo_Use1CManager == True) {				$this->ConnectDB = NULL;
				$All_Message->Add_Message("Объект 'Соединение'", "Инициация подключения WEB сервиса 1С", 0, "Разработчик");

				if (!function_exists('is_soap_fault')){
					$All_Message->Add_Message("Объект 'Соединение'", "Не настроен web сервер. Не найден модуль php-soap", 0, "Разработчик");
					$ReturnValue = False;
				}

				$All_Message->Add_Message("Объект 'Соединение'", "Строка сервиса: " . $this->Str_HTTPWSAdress, 0, "Разработчик");
			    if ($ReturnValue) {

					try {
						// Необходимо отключить кэширование для SOAP. Если этого не сделать,
						// функции веб-сервисов будут работать некорректно.
						ini_set("soap.wsdl_cache_enabled", "0");
						//ini_set("soap.wsdl_cache_ttl", "0");

				    	$this->ConnectDB = new SoapClient($this->Str_HTTPWSAdress, 							//'http://10.80.16.34/upp_test/ws/ws1.1cws?wsdl',
				                               array("login"          => $this->Str_AccountName,
				                                     "password"       => $this->Str_AccountPass,
				                                     "soap_version"   => SOAP_1_2,
				                                     "encoding"       => "UTF-8",
				                                     //"cache_wsdl"     => WSDL_CACHE_NONE, //WSDL_CACHE_MEMORY, //, WSDL_CACHE_NONE, WSDL_CACHE_DISK or WSDL_CACHE_BOTH
				                                     "exceptions"     => True,
				                                     "trace"          => 1,
				                                     "features"       => SOAP_USE_XSI_ARRAY_TYPE
				                                     )
				        );
					} catch(SoapFault $e) {
						$All_Message->Add_Message("Объект 'Соединение'", "Ошибка подключения или внутренняя ошибка сервера. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
						//trigger_error(' Не удалось связаться с базой 1С.', E_ERROR);
						//var_dump($e);
						$ReturnValue = False;
					}
				} else					return $ReturnValue;
			    if (is_soap_fault($this->ConnectDB)){
					$All_Message->Add_Message("Объект 'Соединение'", "Ошибка подключения или внутренняя ошибка сервера. SOAP: (faultcode: {$this->ConnectDB->faultcode}, faultstring: {$this->ConnectDB->faultstring})", 0, "Разработчик", $this->ConnectDB->faultcode);
					//trigger_error('Ошибка подключения или внутренняя ошибка сервера. Не удалось связаться с базой 1С.', E_ERROR);
					$ReturnValue = False;
					$this->ConnectDB = NULL;
			    } else
					$All_Message->Add_Message("Объект 'Соединение'", "Подключение WEB сервиса 1С установлено", 0, "Разработчик");

			} else {

				// проверка существования подключения и его стабильности
				if (isset($this->ConnectDB) && is_object($this->ConnectDB) && ($this->ConnectDB instanceof mysqli)) {
					if ($this->ConnectDB->ping()) {
						return $ReturnValue;
					}
				elseif (isset($this->ConnectDB) && !is_object($this->ConnectDB))
					unset($this->ConnectDB);
				}

				// проверка на заполненность необходимых для подключения параметров
				//if (strlen($this->Str_HostIP) === 0 OR strlen($this->Str_AccountName) === 0 OR strlen($this->Str_DBName) === 0)
				if (strlen($this->Str_HostName) === 0 OR strlen($this->Str_AccountName) === 0 OR strlen($this->Str_DBName) === 0)
				{
					$this->insertLogMessage($All_Message ,"Некоректное заполнение параметров подключения: 'HostName " . $this->Str_HostName . "; AccountName " . $this->Str_AccountName . "; DBName " . $this->Str_DBName . "'");
					$ReturnValue = False;
				}

				// если все проверки удачны
				if ($ReturnValue) {
					$All_Message->Add_Message("Объект 'Соединение'", "Подключение с портом = '" . $this->Int_Port . "' и с сокетом = '" . $this->Str_Socket . "'", 0, "Разработчик");
					// попытка выполнить подключение к серверу
					try {
						// выбор способа подключения в зависимости от настроек
						if ($this->Int_Port <> 0 && strlen($this->Str_Socket) <> 0){
							//@$this->ConnectDB = new mysqli($this->Str_HostIP, $this->Str_AccountName, $this->Str_AccountPass, $this->Str_DBName, $this->Int_Port, $this->Str_Socket);
							@$this->ConnectDB = new mysqli($this->Str_HostName, $this->Str_AccountName, $this->Str_AccountPass, $this->Str_DBName, $this->Int_Port, $this->Str_Socket);
							$All_Message->Add_Message("Объект 'Соединение'", "Подключение с портом и с сокетом", 0, "Разработчик");
							}
						elseif ($this->Int_Port <> 0 && strlen($this->Str_Socket) === 0){
							//@$this->ConnectDB = new mysqli($this->Str_HostIP, $this->Str_AccountName, $this->Str_AccountPass, $this->Str_DBName, $this->Int_Port);
							@$this->ConnectDB = new mysqli($this->Str_HostName, $this->Str_AccountName, $this->Str_AccountPass, $this->Str_DBName, $this->Int_Port);
							$All_Message->Add_Message("Объект 'Соединение'", "Подключение с портом и без сокета", 0, "Разработчик");
							}
						else {
							//@$this->ConnectDB = new mysqli($this->Str_HostIP, $this->Str_AccountName, $this->Str_AccountPass, $this->Str_DBName);
							@$this->ConnectDB = new mysqli($this->Str_HostName, $this->Str_AccountName, $this->Str_AccountPass, $this->Str_DBName);
							$All_Message->Add_Message("Объект 'Соединение'", "Подключение без порта и сокета", 0, "Разработчик");
						}

						// если подключение не удачно
						if ($this->ConnectDB->connect_error){							$MessText = "Connect Error (" . @$this->ConnectDB->connect_errno . ") " . @$this->ConnectDB->connect_error;							$this->insertLogMessage($All_Message , $MessText);
							$All_Message->Add_Message("Объект 'Соединение'", $MessText, 0, "Разработчик");
							throw new Exception("He удалось подключиться к серверу - " . $this->Str_HostName . "! " . $MessText);	// Вызвать исключение подключения к серверу базы данных
						}
					}
					catch (Exception $e) {																		// Обработчик исключения
						$All_Message->Log_GlobalError = true;
						$this->ConnectDB = false;
						$this->insertLogMessage($All_Message ,$e->getMessage());
						$ReturnValue = False;
					}
				}
			}

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
	### getIDRecord(Object ErrorOfModul, String TableSerName, Array Value, Array DataSession)
	### 	вычислить ID записи для указанной таблицы в БД
    	public function getIDRecord($All_Message, $_Str_TableSerName, $Arr_Value, $SystemValue) {   	###------- Входные параметры
	###  Object ErrorOfModul	- Объект хранения сообщений по системе
	###  String TableSerName	- Синоним таблицы в БД
	###  Array Value			- Массив значений, сопоставление [Значение] - [Поле]
	###------- Выходные параметры
	###  Void 					- ID записи в таблице, вернет False если не найдено
	###
			$ReturnValue = True;

			$_Str_TableName = $this->FindTableName($_Str_TableSerName);
			$this->insertLogMessage($All_Message, "Имя поиска таблицы: '" . $_Str_TableName . "'", $SystemValue);
			if (strlen($this->Str_DBName) === 0 or strlen($_Str_TableName) === 0) {
				$this->insertLogMessage($All_Message, "Ошибка поиска имени таблицы. Имя поиска: '" . $_Str_TableName . "'", $SystemValue);
				$ReturnValue = False;
			}
			$SQL_Query = "";
			$MessageText = "";

	 		try {
				// проверка установки соединения
				if ($this->setConnection($All_Message) === False)
					$ReturnValue = False;

				if ($ReturnValue === True){
					$SQL_Query = "SELECT `" . $_Str_TableName . "`.`ID` FROM `" . $_Str_TableName . "` ".
						"WHERE ";
					For ($i = 0; $i < count($Arr_Value); $i++) {
						if ($i > 0)
							$SQL_Query .= " AND ";
						$SQL_Query .= "`" . $_Str_TableName . "`.`" . $Arr_Value[$i]['Поле'] . "` = '" . $Arr_Value[$i]['Значение'] . "'";
					}

					$_ConnectDB = $this->ConnectDB;

					// Принять кодировку для запросов к базе данных
					$_ConnectDB->set_charset("UTF-8");
					$this->insertLogMessage($All_Message, "База данных: '" . $this->Str_DBName . "'. Запрос: '" . $SQL_Query . "'", $SystemValue);
					//выполнить запрос и обработать результат
					if ($Result = $_ConnectDB->query($SQL_Query)) {
			            $i = $Result->num_rows;
			            // если строк не 1, то ошибка
			            if ($i > 1) {
							$ReturnValue = False;
							$this->insertLogMessage($All_Message, "Ошибка поиска ID записи. В результате запроса более 1 строки с заданными параметрами. Запрос: '" . $SQL_Query . "'", $SystemValue);
			    		}
			    		elseif ($i == 0) {							$ReturnValue = False;
							$this->insertLogMessage($All_Message, "Ошибка поиска ID записи. В результате запроса нет строк с заданными параметрами. Запрос: '" . $SQL_Query . "'", $SystemValue);
			    		}
                        else {
	 				        $Row = $Result->fetch_row();
					        $ReturnValue = $Row[0];
					        $Result->close();
						}
					}
					else {
						throw new Exception("He удалось выполнить SQL запрос!" . $_ConnectDB->error);	// Вызвать исключение ошибка SQL запроса
					}
				}
				else
					throw new Exception("Ошибка установки соединения!" . $MainConnection->ConnectDB->error);	// Вызвать исключение ошибка соединения
			}
			catch (Exception $e) {
				//формируем сообщения для разных типов пользователей
				$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка системы. Выполните вход позже", 0);
				if (strlen($SQL_Query) > 0)
					$MessageText = "Ошибка запроса: '" . $SQL_Query . "'! '" . $e->getMessage() . "' Файл:" . $e->getFile() . ", строка:" . $e->getLine();	// Сформировать полную строку лога
				else
					$MessageText = $e->getMessage() . "' Файл:" . $e->getFile() . ", строка:" . $e->getLine();	// Сформировать полную строку лога
				$All_Message->Add_Message("Объект 'Пользователь'", $MessageText, 0, "Разработчик", $e->getCode(), $e->getFile(), $e->getLine());
            	$this->insertLogMessage($All_Message, $MessageText, $SystemValue);                           			// Записать в файл логов ошибку
				$ReturnValue = False;
			}
			if (isset($_ConnectDB))
				unset($_ConnectDB);
			if (isset($i))
				unset($i);
			unset($SQL_Query, $MessageText);
			return $ReturnValue;
    	}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
	### matchNewIDRecord(Object ErrorOfModul, String TableSerName, Bool UseAllNumber)
	### 	вычислить новый ID для указанной таблицы в БД
    	public function matchNewIDRecord($All_Message, $_Str_TableSerName,  $_B_UseAllNumber = 0, $SystemValue, $FromID = "") {
   	###------- Входные параметры
	###  Object ErrorOfModul	- Объект хранения сообщений по системе
	###  String TableSerName	- Синоним таблицы в БД
	###  Bool UseAllNumber		- Признак, указывающий на использование промежуточных записей, а не только последнего номера
	###									0 - не использовать промежуточные записи, 1 - использовать промежуточные записи
	###------- Выходные параметры
	###  Void 					- Новый номер для таблицы. Если попытка вычисления ID неудачна вернет False
	###
		    $ReturnValue = True;

		    $_Str_TableName = $this->FindTableName($_Str_TableSerName);

		    if (strlen($this->Str_DBName) === 0 or strlen($_Str_TableName) === 0) {
###---------
				$All_Message->add_Message("Приложение", "Вычисление нового ID таблицы: '" . $_Str_TableSerName . "' имя таблицы не найдено", 0, "Разработчик");
###---------
		    	$ReturnValue = False;
			}

		    $SQL_Query = "";
		    $MessageText = "";

/*
SELECT ifnull(max(`ID`), 'aaa0000000') FROM `testing`

SELECT IFNULL(MAX(ID), IF(`DATA_TYPE` = 'varchar', 'aaa0000001', 0)) AS 'MaxID'
FROM `UsersSys`, (SELECT `DATA_TYPE` From `information_schema`.`COLUMNS`
WHERE `TABLE_NAME` = 'UsersSys' AND `COLUMN_NAME` = 'ID') AS templTab

SELECT IFNULL(MAX(ID), IF(`DATA_TYPE` = 'varchar', 'aaa0000001', 0)) AS 'MaxID'
FROM `UsersSys`, (SELECT `DATA_TYPE` From `information_schema`.`COLUMNS`
WHERE `TABLE_SCHEMA` = 'Test' AND `TABLE_NAME` = 'UsersSys' AND `COLUMN_NAME` = 'ID') AS templTab
*/
/*
				$SQL_Query = <<<QUERY
				SELECT IFNULL(MAX(ID), IF(`DATA_TYPE` = 'varchar', 'aaa0000001', 0)) AS 'MaxID'
				FROM `$_Str_TableName`,
					(SELECT `DATA_TYPE` From `information_schema`.`COLUMNS`
					WHERE `TABLE_SCHEMA` = '$this->Str_DBName' AND `TABLE_NAME` = '$_Str_TableName' AND `COLUMN_NAME` = 'ID')
				AS templTab
				QUERY;

						$SQL_Query = "SELECT IFNULL(MAX(ID), IF(`DATA_TYPE` = 'varchar', 'aaa0000001', 0)) AS 'MaxID' " .
							"FROM `" . $_Str_TableName . "`, " . "(SELECT `DATA_TYPE` FROM `information_schema`.`COLUMNS` " .
							"WHERE `TABLE_SCHEMA` = '" . $this->Str_DBName . "' AND `TABLE_NAME` = '" . $_Str_TableName . "' AND `COLUMN_NAME` = 'ID') " .
							"AS templTab";
*/
            if ($FromID == "") {
		 		try {
					// проверка установки соединения
					if ($this->setConnection($All_Message) === False)
						$ReturnValue = False;

					if ($ReturnValue === True){
						$SQL_Query = "SELECT IFNULL(MAX(`ID`), 'aaa0000000') AS 'MaxID' " .
							"FROM `" . $_Str_TableName . "`";

						$_ConnectDB = $this->ConnectDB;

						// Принять кодировку для запросов к базе данных
						$_ConnectDB->set_charset("UTF-8");
						if ($Result = $_ConnectDB->query($SQL_Query)) {
	 				        $Row = $Result->fetch_row();
	 				        $ReturnValue = $this->matchNewID($All_Message, $Row[0]);
					        $Result->close();
						}
						else {
							throw new Exception("He удалось выполнить SQL запрос!" . $_ConnectDB->error);	// Вызвать исключение ошибка SQL запроса
						}
					}
					else
						throw new Exception("Ошибка установки соединения!" . $MainConnection->ConnectDB->error);	// Вызвать исключение ошибка SQL запроса
				}
				catch (Exception $e) {
					//формируем сообщения для разных типов пользователей
					$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка системы. Выполните вход позже", 0);
					if (strlen($SQL_Query))
						$MessageText = "Ошибка запроса: '" . $SQL_Query . "'! '" . $e->getMessage() . "' Файл:" . $e->getFile() . ", строка:" . $e->getLine();	// Сформировать полную строку лога
					else
						$MessageText = $e->getMessage() . "' Файл:" . $e->getFile() . ", строка:" . $e->getLine();	// Сформировать полную строку лога
					$All_Message->Add_Message("Объект 'Пользователь'", $MessageText, 0, "Разработчик", $e->getCode(), $e->getFile(), $e->getLine());
	            	$this->insertLogMessage($All_Message, $MessageText, $SystemValue); 						// Записать в файл логов ошибку
					$ReturnValue = False;
				}
				if (isset($_ConnectDB))
					unset($_ConnectDB);
				unset($SQL_Query, $MessageText);
			}
			else {				$ReturnValue = $this->matchNewID($All_Message, $FromID);
			}

			return $ReturnValue;
    	}
    ###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Выполнение запроса
	### execSQLQuery(Object ErrorOfModul, [Object SystemConfig], [String SQLQuery], [bool Muitiple])
	### 	Выполнение переданного запроса
		public function execSQLQuery(ErrorOfModul $All_Message, $SystemValue = Null, $SQLQuery = Null, $Muitiple = False, $InTranzact = False) {
			$ReturnValue = True;


			if ((is_string($SQLQuery) && strlen(trim($SQLQuery)) == 0) || (is_array($SQLQuery) && count($SQLQuery) === 0) || $SQLQuery == Null) {
				if (strlen(trim($this->SQLQuery)) == 0)
					$ReturnValue = False;
				else
					$SQLQuery = $this->SQLQuery;
			}

			/*
			if(is_array($SQLQuery)){
				$All_Message->Add_Message("Объект 'Банер'", "Запрос для записи МАССИВ: '" . $SQLQuery . "'" , 0, "Разработчик");
			}
			Else{
				$All_Message->Add_Message("Объект 'Банер'", "Запрос для записи НЕ МАССИВ: '" . $SQLQuery . "'" , 0, "Разработчик");
			}
			*/

			if ($ReturnValue) {				if ($this->setConnection($All_Message)) {					try {
						$Str_DBName = $SystemValue->getSystemName();
						$this->ConnectDB->set_charset("UTF-8");
	                    If ($InTranzact && is_array($SQLQuery)) {		                    //Выполнение запроса в транзакции
							$this->ConnectDB->autocommit(False);
							$this->ConnectDB->begin_transaction();
							Foreach($SQLQuery As &$Value) {
								//echo $Value . "<br />";
								If (!$Result = $this->ConnectDB->query($Value)){
									$Message = "Ошибка запроса: '" . $Value . "' - '" . $this->ConnectDB->error;
									$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $this->ConnectDB->errno, "", "", "");
									$this->insertLogMessage($All_Message, $Message, $SystemValue);
									//echo "Ошибка запроса: " . $MainConnect->ConnectDB->errorno . ": `" . $MainConnect->ConnectDB->error . "`<br />";
									$ReturnValue = False;
									Break;
								}
								Else
									unset($Result);
							}

							If ($ReturnValue) {
								//echo "Фикс <br />";
								$this->ConnectDB->commit();
							}
							Else{
								//echo "Отмена <br />";
								$this->ConnectDB->rollback();
							}
							$this->ConnectDB->autocommit(True);
	                    }
	                    Elseif ($Muitiple) {	                    	//выполнение мультизапроса	                    	$this->ConnectDB->multi_query($SQLQuery);
	                    }
	                    else {
	                    	//выполнение одиночного запроса
							if ($Result = $this->ConnectDB->query($SQLQuery))
								$ReturnValue = $Result;
							else {
								$Message = "Ошибка запроса: '" . $SQLQuery . "' - '" . $this->ConnectDB->error;
								$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $this->ConnectDB->errno, "", "", "");
								$ReturnValue = False;
								$this->insertLogMessage($All_Message, $Message, $SystemValue);
							}
						}
					}
					catch (Exception $e) {						$ReturnValue = False;
						$Message = "Ошибка: " . $e->getMessage() . " в файле: " . $e->getFile() . " - строка: " . $e->getLine();
						$this->insertLogMessage($All_Message, $Message, $SystemValue);
					}
				}
			}
			if (isset($Message))
				unset($Message);
			if (isset($Result))
				unset($Result);
			unset($SQLQuery);

            return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
	### insertLogMessage(Object ErrorOfModul, String Message)
	### 	записать сообщения в журнл логов и в объект "Сообщения"
		public function insertLogMessage($All_Message, $Message, $SystemValue = Null) {
	###------- Входные параметры
	### Object ErrorOfModul		- Объект, содержащий ошибки
	### String Message			- срока с сообщением
	###------- Выходные параметры
	###  Bool 	- признак выполненной функции
	###
			// Формируем имя файла логов
			if ($SystemValue == Null || (isset($SystemValue) && $SystemValue->getUseValueBD() == False)) {
				$S_LogFile = Str_PathFileLogs . Str_NameFileLogs;
				$Str_DBName = Str_DBName;
			}
			else {
				$S_LogFile = $SystemValue->getLogFile();
				$Str_DBName = $SystemValue->getSystemName();
			}

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
					@fclose($Handler);                                                               // Закрыть файл
					unset($Str_IP, $Str_Forward, $NkB);
				}
				else
					throw new FOException($Message . ". Не возможно открыть файл!");                // Вызвать обработчик ошибки открытия файла
			}
			catch (FOException $e) {                                                                // Обработчик ошибки открытия файла
				$All_Message->Log_GlobalError = true;
				$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $e->getCode(), $e->getFile(), $e->getLine());
			}
			if (isset($e))
				unset($e);
			if (isset($Handler))
				unset($Handler);
			unset($S_LogFile);
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	###////// Закрытые

    ###@@@@@@@@@@@@@@@@@@@@@
	### FindTableName(String TableSerName)
	### 	найти имя таблицы в БД
		private function FindTableName($_Str_TableSerName) {
   	###------- Входные параметры
	###  String TableSerName	- синоним таблицы
	###------- Выходные параметры
	###  String - имя таблицы в БД
	###
			$ReturnValue = "";

			switch ($_Str_TableSerName) {				case "Установленные категории":
					$ReturnValue = "usercategoryins";
					break;				case "Категории":
					$ReturnValue = "categorylist";
					break;
				case "Адреса электронной почты":
					$ReturnValue = "tableemailusers";
					break;
				case "Пользователи приложения":
					$ReturnValue = "userssys";
					break;
				case "ФИО":
					$ReturnValue = "peoplelist";
					break;
				case "Банер":
					$ReturnValue = "banerstable";
					break;
				case "Тип банера":
					$ReturnValue = "banerstypelist";
					break;
				case "Ссылка на банер":
					$ReturnValue = "banershttplink";
					break;
				case "Ссылка на картинку":
					$ReturnValue = "tableuserlinks";
					break;
				case "Номенклатура":
					$ReturnValue = "nomenclature";
					break;
				case "Строка адреса интернет":
					$ReturnValue = "banershttplink";
					break;
				case "Тип номенклатуры":
					$ReturnValue = "typenomenclature";
					break;
			}

			return $ReturnValue;
    	}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
	### matchNewID(Object ErrorOfModul, Void OldMaxNum)
	### 	вычислить новый ID
    	private function matchNewID($All_Message, $_OldMaxNum) {
   	###------- Входные параметры
	###  Object ErrorOfModul	- Объект хранения сообщений по системе
	###  Void OldMaxNum			- Максимальное значение, используемое в БД
	###------- Выходные параметры
	###  Void - Новый номер для таблицы. Если попытка вычисления ID неудачна вернет False
	###
            $ReturnValue = True;

            if (is_int($_OldMaxNum) === True){
            	if ($_OldMaxNum < 99999999999){
            		$_OldMaxNum ++;
            		$ReturnValue = $_OldMaxNum;
            	}
            	else
            		$ReturnValue = False;
            }
            elseif (is_string($_OldMaxNum) === True){
            	$PrefixOld = substr($_OldMaxNum, 0, 3);
            	$NumOld = substr($_OldMaxNum, 3);
            	$LenNum = strlen($NumOld);
            	$NumOld = (int)$NumOld;
            	if ($NumOld < 9999999) {
					$NumOld ++;
					$NewNum = (string)($NumOld);
					while (strlen($NewNum) < $LenNum) {
						$NewNum = "0".$NewNum;
					}
					$ReturnValue = $PrefixOld . $NewNum;
					unset($NewNum);
				}
				else {
					$_NewPrefix = "";
					$_NextSimvUp = True;
					for ($i = strlen($PrefixOld) - 1; $i >= 0; $i = $i - 1) {
					$_KodSimv = ord(substr($PrefixOld, $i, 1));
					if ($_NextSimvUp) {
	                		if ($_KodSimv === 90)
	                		{
	                			$_KodSimv = 98;
	                			$_NextSimvUp = False;
	                		}
	                		elseif ($_KodSimv === 122) {
	                			$_KodSimv = 192;
	                			$_NextSimvUp = False;
	                		}
	                		elseif ($_KodSimv === 255) {
	                			if ($i === 0)
	                				$ReturnValue = False;
								else {
		                			$_KodSimv = 65;
		                			$_NextSimvUp = True;
	                			}
	                		}
	                		else {
	                			$_NextSimvUp = False;
	                			$_KodSimv ++;
	                		}
						}
                		$_NewPrefix = chr($_KodSimv) . $_NewPrefix;
                	}
            		if ($ReturnValue) $ReturnValue = $_NewPrefix . "0000001";
            		if (isset($_KodSimv)) unset($_KodSimv);
            		unset($_NewPrefix, $_NextSimvUp);
            	}
            	unset($PrefixOld, $NumOld, $LenNum);
            }
            else
            	$ReturnValue = False;
			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	}
	////////////////////////////////////////////////////
    ######      Конец описания объекта             #####
	####################################################
?>
