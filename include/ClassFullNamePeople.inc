<?php
	####################################################
	########    Объект наименование "Людей"       ######
	####################################################
	class FullNamePeople{
 	### Наименование - FullNamePeople
 	###  	Объект для хранения и обработки объекта автоматизации "ФИО Человека"
    ###
    ###-------------------------------------------------
    ###  Требуются объекты для работы
    ### ErrorOfModul All_Message		// Объект "Сообщения системы"
    ### Connections MainConnect			// Объект "Соединение с БД"
	### SystemConfig SystemValue		// Объект "Конфигурация приложения"
	////////////////////////////////////////////////////
 	################    Свойства    ####################
	////////////////////////////////////////////////////
 	###////// Открытые
	###	_P_ID;				// Публичный идентификатор
	###	_S_NickName;			// Псевдоним
 	###------------------------------------------------
 	###////// Защищенные
	###	_S_FirstName		// Имя
	###	_S_SecondName		// Отчество
	###	_S_LastName			// Фамилия
	###	_B_SexMen			// Пол	0 - Женщина
	### 							1 - Мужчина
	###	S_FullName			// Полное имя
	###	S_ShortName			// Короткое имя
 	###------------------------------------------------
 	###////// Внутренние
	###	_S_ID				// Иденитификатор человека в БД
	###	_B_NewMen			// Признак создания нового человека
	###
 	###------------------------------------------------
	###////// Требующие реализации
	###
	////////////////////////////////////////////////////
	###########   Методы класса   ######################
	////////////////////////////////////////////////////
	###////// Открытые
	###
	###  __construct([String ID[, String FirstName[, String SecondName[, String LastName[, Bool Sex]]]]])
	###										:Oblect	- Конструктор класса
	###  __set(String Name_Var, Void _Value_Var)
	###										:Void	- Установить значение свойства класса
	###  __get(String Name_Var)				:Void	- Прочитать значение переменной
	###  setPeopleID(String ID)				:Bool	- Установить ID объекта
	###  getPeopleID()						:String	- Получить ID объекта в БД
    ###  setPeopleName([String FirstName[, String SecondName[, String LastName[, Bool Sex]]]])
	###										:Bool	- Установить значения свойств объекта
	###
	////////////////////////////////////////////////////
	###////// Наследуемые
	###
	###  сreateShortName(String FirstName, String SecondName, String LastName)
	###										:String	- Сформировать короткое наименование объекта
	###  сreateFullName(String FirstName, String SecondName, String LastName)
	###										:String	- Сформировать полное имя объекта
	###  modyStandartName(String var)
	###										:String	- Преобразовать строку к формату "Иван".
	###
	////////////////////////////////////////////////////
	###////// Внутренние
	###
	###	 readPeoleFromBase(Object Connections, Object ErrorOfModul, String ID)
	###										:Bool	- считать данные по ID из БД
	###
	////////////////////////////////////////////////////
	##########       Свойства класса       #############
	////////////////////////////////////////////////////
 	### Открытые
		public $_P_ID;					// Публичный идентификатор
		public $_S_NickName;				// Псевдоним
 	### Наследуемые
		protected $_S_FirstName;		// Имя
		protected $_S_SecondName;		// Отчество
		protected $_S_LastName;			// Фамилия
		protected $_B_SexMen;			// Признак пола 0 - Женщина
										//				1 - Мужчина
		protected $S_FullName;			// Полное имя
		protected $S_ShortName;			// Короткое имя
 	### Внутренние
		private $_S_ID;					// Иденитификатор человека в БД
		private $_B_NewMen;				// Признак нового объекта

	////////////////////////////////////////////////////
	##########        Методы класса        #############
	////////////////////////////////////////////////////

	###////// Открытые

    ###@@@@@@@@@@@@@@@@@@@@@
	###  Конструктор класса
	### __construct([String ID[, String FirstName[, String SecondName[, String LastName[, Bool Sex]]]]])
	### 	Создание объекта класса
		function __construct($_ID = "", $_FirstName = "", $_SecondName = "", $_LastName = "", $_BSexMen = 0) {
	###------- Входные параметры
	###  String ID			- идентификатор объекта в БД
	###  String FirstName	- Имя
	###  String SecondName	- Отчество
	###  String LastName	- Фамилия
	###  Bool Sex			- пол	0 - Женщина
	###								1 - Мужчина
	###------- Выходные параметры
	###  Object - объект типа FullNamePeople
	###
			$_FirstName = $this->modyStandartName($_FirstName);
			$_SecondName = $this->modyStandartName($_SecondName);
			$_LastName = $this->modyStandartName($_LastName);
			$this->_S_ID = $_ID;
			$this->_P_ID = "";
			$this->_S_NickName = "";
			$this->S_FullName = $this->сreateFullName($_FirstName, $_SecondName, $_LastName);
			$this->S_ShortName = $this->сreateShortName($_FirstName, $_SecondName, $_LastName);
			$this->_S_FirstName = $_FirstName;
			$this->_S_SecondName = $_SecondName;
			$this->_S_LastName = $_LastName;
			$this->_B_SexMen = $_BSexMen;
			$this->_B_NewMen = 1;
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
			//if ($_Name_Var != "_S_ID" && $_Name_Var != "S_ShortName" && $_Name_Var != "S_FullName")
			if ($_Name_Var != "_S_ID")
				$this->$_Name_Var = $_Value_Var;
			else				$this->$_Name_Var = "";
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
			$ReturnValue = false;
			if ($_Name_Var != "_S_ID")
				$ReturnValue = $this->$_Name_Var;

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  setPeopleID()
    ###     установить идентификатор объекта
		function setPeopleID($_ID) {
	###------- Входные параметры
	###  String ID					- идентификатор в таблице БД
	###------- Выходные параметры
	###  Bool - признак удачного выполнения функции
	###
			$this->_S_ID = $_ID;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  getPeopleID()
    ###     получить идентификатор объекта в БД
		function getPeopleID() {
	###------- Входные параметры
	### ---
	###------- Выходные параметры
	###  String - строковое значение идентификатор объекта в БД
	###
			return $this->_S_ID;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  setPeopleName([String FirstName[, String SecondName[, String LastName[, Bool Sex]]]])
    ###     установить значения переменных класса
		function setPeopleName($_FirstName = "", $_SecondName = "", $_LastName = "", $_SexMen = 0) {
	###------- Входные параметры
	###  String FirstName	- Имя
	###  String SecondName	- Отчество
	###  String LastName	- Фамилия
	###  Bool Sex			- пол	0 - Женщина
	###								1 - Мужчина
	###------- Выходные параметры
	###  Bool - признак удачного выполнения функции
	###
 			$_FirstName = $this->modyStandartName($_FirstName);
			$_SecondName = $this->modyStandartName($_SecondName);
			$_LastName = $this->modyStandartName($_LastName);
			//$this->S_FullName = $this->сreateFullName($_FirstName, $_SecondName, $_LastName);
			//$this->S_ShortName = $this->сreateShortName($_FirstName, $_SecondName, $_LastName);
			$this->_S_FirstName = $_FirstName;
			$this->_S_SecondName = $_SecondName;
			$this->_S_LastName = $_LastName;
			$this->_B_SexMen = $_SexMen;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	////////////////////////////////////////////////

	###////// Наследуемые

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  сreateShortName(String FirstName, String SecondName, String LastName)
    ###     Создать короткое наименование объекта
		protected function сreateShortName($_FirstName, $_SecondName, $_LastName) {
	###------- Входные параметры
	###  String FirstName	- Имя
	###  String SecondName	- Отчество
	###  String LastName	- Фамилия
	###------- Выходные параметры
	###  String - строковое значение короткое имя в виде "А. А. Иванов" или "А. Иванов" или "Иванов" или ""
	###				в зависимсти от полученных данных
	###
			$_S_ShortName = "";
			if (strlen($_LastName) !== 0)
			{
				$_S_ShortName = $_LastName;
				if (strlen($_FirstName) !== 0 and strlen($_SecondName) !== 0)
					$_S_ShortName = mb_substr($_FirstName, 0, 1, 'UTF-8') . ". " . mb_substr($_SecondName, 0, 1, 'UTF-8') . ". " . $_S_ShortName;
				elseif (strlen($_FirstName) !== 0)
					$_S_ShortName = mb_substr($_FirstName, 0, 1, 'UTF-8') . ". " . $_S_ShortName;
			}
			return $_S_ShortName;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  сreateFullName(String FirstName, String SecondName, String LastName)
    ###     Создать полное наименование объекта
		protected function сreateFullName($_FirstName, $_SecondName, $_LastName) {
	###------- Входные параметры
	###  String FirstName	- Имя
	###  String SecondName	- Отчество
	###  String LastName	- Фамилия
	###------- Выходные параметры
	###  String - строковое значение короткое имя в виде "Иван Иванович Иванов" или "Иван Иванов" или "Иванов" или ""
	###				в зависимсти от полученных данных
	###
			$_S_FullName = "";
			if (strlen($_LastName) !== 0)
			{
				$_S_FullName = $_LastName;
				if (strlen($_FirstName) !== 0 and strlen($_SecondName) !== 0)
					$_S_FullName = $_FirstName . " " . $_SecondName . " " . $_S_FullName;
				elseif (strlen($_FirstName) !== 0)
					$_S_FullName = $_FirstName . " " . $_S_FullName;
			}
			return $_S_FullName;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  modyStandartName(String var)
    ###     Модифицировать строку
		protected function modyStandartName($_NameForMody) {
	###------- Входные параметры
	###  String var			- Строка для преобразования
	###------- Выходные параметры
	###  String - строковое значение приведенное к виду "Иван".
	###			Вернет "" при пустой строке или заполненную пробелами
	###
			if (is_string($_NameForMody)) {
				$_NameForMody = trim($_NameForMody);
				if (strlen($_NameForMody) != 0)
						$_NameForMody = mb_strtoupper(mb_substr($_NameForMody, 0, 1, 'UTF-8'), 'UTF-8') . mb_substr(mb_convert_case($_NameForMody, MB_CASE_LOWER, 'UTF-8'), 1, mb_strlen($_NameForMody), 'UTF-8');
						//$_NameForMody = ucfirst(strtolower($_NameForMody));
			}
			else
				$_NameForMody = "";

			return $_NameForMody;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	////////////////////////////////////////////////

	###////// Внутренние

    ###@@@@@@@@@@@@@@@@@@@@@
    ###  readPeoleFromBase(Object Connections, Object ErrorOfModul, String ID)
    ###     прочитать данные объекта из БД
		private function readPeoleFromBase($MainConnect, $SystemValue = Null, $All_Message, $_S_ID) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  String ID					- идентификатор в таблице БД
	###------- Выходные параметры
	###  Bool - признак удачного выполнения функции
	###
    ###------------------------------------------------------------------
			$ReturnValue = False;

			// проверка на не пустое значение искомого ID
			if (strlen(trim($_S_ID)) !== 0) {
				$SQLQuery = "SELECT `ID`, `FirstName`, `SecondName`, `LastName`, `Sex` FROM `peoplelist` WHERE `ID` = '" . $_S_ID . "'";
				if ($Result = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQLQuery)) {
				        $Row = $Result->fetch_row();
					$this->_S_ID = (string)$Row[0];
					$this->_S_FirstName = (string)$Row[1];
					$this->_S_SecondName = (string)$Row[2];
					$this->_S_LastName = (string)$Row[3];
					$this->_B_SexMen = (bool)$Row[4];
					//$this->S_FullName = $this->сreateFullName($this->_S_FirstName, $this->_S_SecondName, $this->_S_LastName);
					//$this->S_ShortName = $this->сreateShortName($this->_S_FirstName, $this->_S_SecondName, $this->_S_LastName);
			        $Result->close();
					$ReturnValue = True;
				}

				if (isset($Result))
					unset($Result);
				if (isset($Row))
					unset($Row);
				unset($SQLQuery);

				if ($ReturnValue === True)
					$this->_B_NewMen = 0;

			}
			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

	////////////////////////////////////////////////////
    ######      Конец описания объекта             #####
	####################################################
	}

?>
