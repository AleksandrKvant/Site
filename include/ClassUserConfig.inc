<?php
	####################################################
	########        Объект пользователь           ######
	####################################################
	class UserConfig extends FullNamePeople {
	### Наименование -
	###		Объект для хранения и обработки объекта автоматизации "Пользователь"
	### Является потомком каласса FullNamePeople,
	###		как следствие - необходим класс родитель для работы с этим классом
	###
	###-------------------------------------------------
	###		Требуются объекты для работы
	### ErrorOfModul All_Message		// Объект "Сообщения системы"
	### Connections MainConnect			// Объект "Соединение с БД"
	### SystemConfig SystemValue		// Объект "Конфигурация приложения"
	////////////////////////////////////////////////////
	################    Свойства    ####################
	////////////////////////////////////////////////////
	###////// Открытые
	###	S_User_Nik			// Ник пользователя
	###	_Arr_UserImgLinks	// Доступные ссылки на графические объекты пользователя
	###------------------------------------------------
	###////// Внутренние
	###	_S_UserId			// Иденитификатор пользователя в БД
	###	_S_UserLogin		// Логин пользователя, для входа в систему
	###	_S_UserPassword		// Пароль пользователя в зашифрованном виде
	###	_Array_UserCategory	// Массив категорий пользователя
	###	_Array_EMail		// Массив объектов типа Электронная почта
	### _B_UseCoockies;		// Признак использования пользователем Cookies
	### _B_UserActive;		// Признак активации пользователя
	### _B_UserBlock;		// Признак блокировки пользователя
	### _S_MotiveBlockID;	// Код мотивации блокировки
	### _S_MotiveBlock;		// Мотивация блокировки
	### _B_UserAgreePolicyData
	###
 	###------------------------------------------------
	###////// Требующие реализации
	###	_Array_Documents	// Массив объектов типа Документ
	###	_Array_Telefons		// Массив объектов типа Телефон
	###	_Array_Adress		// Массив объектов типа Адрес
	###	"ЮрФизЛицо" => 1,                    // 0 - юридическое лицо; 1 - физическое лицо
	###	"ВидКонтрагента" => 0,               // 0 - юридическое лицо; 1 - Физическое лицо; 2- Юридическое не резидент; 3 - Индивидуальный предприниматель
	###
	////////////////////////////////////////////////////
	###########   Методы класса   ######################
	////////////////////////////////////////////////////
	###////// Открытые
	###
	### __construct([String NikName[, String FirstName[, String SecondName[, String LastName]]]])
	###						:Oblect		- Конструктор класса
	###  __set(String Name_Var, Void _Value_Var)
	###						:Void		- Установить значение свойства класса
	###  __get(String Name_Var)
	###						:Void		- Прочитать значение переменной
	### getUserID()			:String		- получить значение свойства ID объекта
	### isDeveloper()		:Bool		- проверка пользователя, являтся ли он разработчиком
	### isAdministrator()	:Bool		- проверка пользователя, являтся ли он администратором
	### getUserFIO()		:String		- получить ФИО пользователя
	### getAgreeConfData()	:Boolean	- получить признак что пользователь согласен с политикой портала
	### getUseCookies()		:Boolean	- вернуть значение свойства признака использования Cookies
	### getCategory()		:Array		- получить массив категорий
	### getEMail()			:Array		- получить массив адресов электронной почты
	### getConfirmEMailText(String STR_EMail)
	### 					:String 	- получить код подтверждения адреса EMail
	### readUserFromBase(Object Connection, Object ErrorOfModul, Object SystemConfig, String Login, Sting HASH Password, Object DataSession)
	###						:Bool		- прочитать пользователя из БД по логину и паролю пользователя
	###	readUserFromBaseByID(Object Connection, Object ErrorOfModul, Object SystemConfig, Object DataSession)
	###						:Bool		- прочитать данные объекта из БД по ID пользователя
	### createNewUser(Object Connection, Object ErrorOfModul, Object SystemConfig, String Login, String HASH Password, String EMAil, Object DataSession, Bool UseAllNumber)
	###						:Bool		- инициализировать создание нового пользователя системы
	### saveUser(Object Connection, Object ErrorOfModul, Object DataSession, Object SystemConfig, Array Arr_UserData
	###						:Bool		- инициализировать запись измененных данных пользователя
	### readAllImageUrl(Object Connection, Object ErrorOfModul, Object SystemConfig)
	###						:Bool 		- инициировать чтение доступных ссылок на графические объекты пользователя
	### updateUserServices(Object Connection, Object ErrorOfModul, Object SystemConfig, Array Arr_Data)
	###						:Bool		- инициировать изменение данных пользователя через сервис обслуживания
	###
	###////// Открытые текущего проекта
	###
	### getBanersList()		:Array of BanerProperties - получить массив банеров пользователя
	### readBanersList(Object Connection, Object ErrorOfModul, Object DataSession)
	### 					:bool - получить массив объектов банеров принадлежащих пользователю
	###
	////////////////////////////////////////////////////
	###////// Внутренние
	### saveUserToBase1CMetod(Object Connection, Object ErrorOfModul, Array SystemConfig, Array Arr_UserData)
	###						:Bool		- записать данные нового пользователя в БД 1С
	### saveNewUserToBase(Object Connections, Object ErrorOfModul, Object DataSession, Bool UseAllNumber)
	###						:Bool		- записать данные нового пользователя в БД
	### saveUserToBase(Object Connections, Object ErrorOfModul, Object DataSession)
	###						:Bool		- записать данные пользователя в БД
	### readImageUrls1CWebMetod(Object Connection, Object ErrorOfModul, Object DataSession)
	### 					:Bool		- прочитать графические объекты текущего пользователя Web методом 1С
	### ReadImageUrlsFromBase(Object Connection, Object ErrorOfModul, Object DataSession)
	### 					:Bool		- прочитать графические объекты текущего пользователя
	### readUserData1CMetod(Object Connection, Object SystemConfig, Object ErrorOfModul, Integer Metod)
	###						:Bool		- прочитать данные пользователя из БД 1С, функция заполняет прочитанными из БД 1С значениями свойства класса
	### readUserData(Object Connection, Object ErrorOfModul, Integer Metod)
	### 					:Bool		- прочитать данные пользователя из БД, функция заполняет прочитанными из БД значениями свойства класса
	### getUserLogin()		:String		- получить значение свойства логин пользователя
	### getCategoryID(Object Connection, Object ErrorOfModul, String NameCategory)
	###						:String		- получить идентификатор категории в БД
	### setUsePassword()	:Bool		- установить свойство использовать пароль
	### setUserID(String ID)
	###						:Bool		- установить свойство ID объекта
	### setUserLogin(String Login)
	###						:Bool		- установить свойство логин пользователя
	### setUserPassword(String Password)
	###						:Bool		- установить свойство пароль пользователя
	###	FindCategory(String Category)
	###						:Bool		- найти в массиве категорий необходимую категорию
	###	ControlData(Object ErrorOfModul, Array Data)
	###						:Bool		- контроль данных сессии на возможные ошибки
	###	UpdateData(Array Data)
	###						:Bool		- обновить данные объекта согласно данных сессии пользователя
	### createConfirmEMailText(String S_EMail, String S_DateConfirm)
	### 					:String 	- сгенерировать код подтверждения адреса EMail
	### getConfirmEMailText(String STR_EMail, String S_DateConfirm)
	### 					:String 	- получить код подтверждения адреса EMail
	### updateDataUser1CMethod(Object Connection, Object ErrorOfModul, Object SystemConfig, Array Arr_Data)
	###						:Bool		- выполнить изменение данных пользователя сервисными службами методом 1С
	### updateDataUserPHPMethod(Object Connection, Object ErrorOfModul, Object SystemConfig, Array Arr_Data)
	###						:Bool		- выполнить изменение данных пользователя сервисными службами
	###
	###////// Внутренние текущего проекта
	###
	###@@@@@@@@@@@@@@@@@@@@@
	### ReadBanersListFromBase(Object Connection, Object ErrorOfModul, Object DataSession)
	### 					:bool 		- прочитать объекты банеров пользователя из БД
	###
	////////////////////////////////////////////////////
	##########      Свойства класса        #############
	////////////////////////////////////////////////////
	### Открытые свойства
		public $_P_ID;						// Общедоступный иденитификатор объекта в БД
		public $S_User_Nik;					// Ник пользователя
		public $_Arr_UserImgLinks;			// Доступные ссылки на графические объекты пользователя
	### Защищенные свойства
		protected $_S_UserLogin;			// Логин пользователя
		protected $_B_UserBlock;			// Признак блокировки пользователя
		protected $_S_MotiveBlockID;		// Код мотивации блокировки
		protected $_S_MotiveBlock;			// Мотивация блокировки
		protected $_N_VidUser;				// Форма юридического образования пользователя:
											// 			0 - ЮридическоеЛицо
											// 			1 - ФизическоеЛицо
		protected $_N_TypeUser;				// Тип пользователя:
											// 			0 - ЮрЛицо
											//			1 - ФизЛицо
											//			2 - ЮрЛицоНеРезидент
											//			3 - ИндивидуальныйПредприниматель
		protected $_Array_UserCategory;		// Массив категорий, в которых пользователь определен системой
		protected $_Array_EMail;			// Массив адресов электронной почты
		protected $_D_DateIn;				// Дата последнего подключения
		protected $_S_Client;				// Используемый клиент(браузер)
	### Защищенные свойства текущего проекта
		protected $_Arr_Baners;				// Массив ссылок банеров пользователя
	### Закрытые свойства
		private $_S_UserId;					// Идентификатор пользователя в БД
		private $_B_SubscribeNews;			// Признак подписки на новости/рассылки
		private $_B_UserAgreePolicyData;
		private $_B_UserAgreeConfData;		// Признак, что пользователь согласен с политикой конфиденциальности
		private $_B_UserNew;				// Признак, что пользователь новый
		private $_S_UserPassword;			// Пароль пользователя
		private $_B_UserActive;				// Признак активации пользователя
		private $_B_UseCoockies;			// Признак использования пользователем Cookies
		private $_B_UsePassword;			// Признак использования пароля
		private $_S_IPFrom;					// IP адрес с котого выполнен вход
		private $_S_Refferer;				// Адрес, с которого был вызов страницы
		private $_S_Forwarded;				// Адрес, через который был вызов страницы

	////////////////////////////////////////////////////
	##########        Методы класса        #############
	////////////////////////////////////////////////////

	###////// Открытые

	###@@@@@@@@@@@@@@@@@@@@@
	### Конструктор класса
	###	__construct([String NikName[, String FirstName[, String SecondName[, String LastName[, Bool Sex]]]]])
	###		- конструктор класса
		Function __construct($_UserNik = "", $_FirstName = "", $_SecondName = "", $_LastName ="", $_SexMen = 0) {
	###------- Входные параметры
	###  String NikName			- Ник
	###  String FirstName		- Имя
	###  String SecondName		- Отчество
	###  String LastName		- Фамилия
	###  Bool Sex				- Пол
	###------- Выходные параметры
	###  Object 	- объект
	###
			// присвоить начальные значения переменным класса
			$this->S_User_Nik = trim($_UserNik);
			$this->_B_UserNew = False;
			$this->_S_UserId = "";
			$this->_P_ID = "";
			$this->_B_SubscribeNews = False;
			$this->_S_UserLogin = "";
			$this->_S_UserPassword = "";
			$this->_N_VidUser = null;
			$this->_N_TypeUser = null;
			$this->_B_UserActive = 0;
			$this->_B_UserBlock = 0;
			$this->_S_MotiveBlockID = '';
			$this->_S_MotiveBlock = '';
			$this->_Array_UserCategory = array();
			$this->_Array_EMail = array();
			$this->_B_UsePassword = True;
			$this->_B_UseCookies = False;
			$this->_B_UserAgreeConfData = False;
			$this->_B_UserAgreePolicyData = False;
			$this->_D_DateIn = "";
			$this->_S_Client = "";
			$this->_S_IPFrom = "";
			$this->_S_Refferer = "";
			$this->_S_Forwarded = "";
			$this->_Arr_UserImgLinks = array();
			// вызвать конструктор класса родителя
			parent::__construct("", $_FirstName, $_SecondName, $_LastName, $_SexMen);

			$this->_Arr_Baners = array();
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Установка значений класса
	### __set(String Name_Var, Void _Value_Var)
	### 	установка защищенных значений свойств класса
		Function __set($_Name_Var, $_Value_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###  Void _Value_Var			- Значение переменной
	###------- Выходные параметры
	###
			if ($_Name_Var != "_S_UserPassword")
				$this->setUserPassword($_Value_Var);
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Считывание значений свойств класса
	### __get(String Name_Var)
	### 	Считывание защищенных свойств класса
		Function __get($_Name_Var) {
	###------- Входные параметры
	###  String _Name_Var			- Наименование переменной
	###------- Выходные параметры
	###  Void _Value_Var			- Значение переменной
	###
			$_ReturnValue = false;
			if ($_Name_Var != "_S_UserId" && $_Name_Var != "_S_ID" && $_Name_Var != "_S_UserPassword" && $_Name_Var != "_Arr_Baners")
				$_ReturnValue = $this->$_Name_Var;

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUserID()
	### 	- вернуть значение свойства ID пользователя
		Function getUserID() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  String 	- значение свойства ID
	###
			return $this->_S_UserId;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getAgreeConfData()
	### 	- вернуть значение свойства признака согласия с политикой сайта
		Function getAgreeConfData() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Boolean 	- значение свойства _B_UserAgreeConfData
	###
			return $this->_B_UserAgreeConfData;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUseCookies()
	### 	- вернуть значение свойства признака использования Cookies
		Function getUseCookies() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Boolean 	- значение свойства _B_UseCookies
	###
			return $this->_B_UseCoockies;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	isDeveloper
	###		- проверка на, является ли пользователь разработчиком
		Function isDeveloper() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Bool 	- признак найденной категории
	###
			$_ReturnValue = False;
			// проверка массива на количество элементов
			if (is_array($this->_Array_UserCategory)) {
				for ($i = 0; $i < count($this->_Array_UserCategory); $i++)
					if ($this->_Array_UserCategory[$i] === "Разработчик"){
						$_ReturnValue = True;
						break;
					}
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	isAdministrator
	###		- проверка на, является ли пользователь администратором
		Function isAdministrator() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Bool 	- признак найденной категории
	###
			$_ReturnValue = False;
			// проверка массива на количество элементов
			if (is_array($this->_Array_UserCategory)) {
				for ($i = 0; $i < count($this->_Array_UserCategory); $i++)
					if ($this->_Array_UserCategory[$i] === "Администратор"){
						$_ReturnValue = True;
						break;
					}
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	readUserFromBaseByID(Connections Connection, SystemConfig SystemValue, ErrorOfModul ErrorOfModul, Array Data)
	###		- прочитать данные объекта из БД по ID пользователя
		Function readUserFromBaseByID($MainConnect, $SystemValue, $All_Message, $Arr_Sess) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###  Array Data							- Данные сессии
	###------- Выходные параметры
	###  Bool 	- признак удачного чтения данных
	###
			// внутрениие переменные функции
			$_ReturnValue = True;

			if (strlen($Arr_Sess["S_IDUser"]) === 0)
				$_ReturnValue = False;
			else
				$this->_P_ID = $Arr_Sess["S_IDUser"];
			//	$this->_S_UserId = $Arr_Sess["S_IDUser"];
			if ($_ReturnValue)
				$_ReturnValue = $this->ControlData($All_Message, $Arr_Sess);

			// При прохождении всех проверок выполнить чтение данных
			if ($_ReturnValue)
				$_ReturnValue = $this->readUserData($MainConnect, $SystemValue, $All_Message, 1);
			else
				$All_Message->Add_Message("Объект 'Пользователь'", "Не удалось прочитать данные пользователя. Выполните вход позже", 0, "Пользователь");

			if ($_ReturnValue)
				$this->UpdateData($Arr_Sess);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	readUserFromBase(Connections Connection, SystemConfig SystemValue, ErrorOfModul ErrorOfModul, String Login, String HASH Password, Array DataSession)
	###		- прочитать данные объекта из БД по логину и паролю пользователя
		Function readUserFromBase($MainConnect, $SystemValue, $All_Message, $_UserLogin, $_UserPassword, $Arr_Sess = NULL) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul		- Объект хранения сообщений по системе
	###  String Login				- Login пользователя в БД
	###  String HASH Password		- пароль пользователя
	###  Array DataSession			- данные сессии пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного чтения данных
	###
			// внутрениие переменные функции
			$_NumCharLogin = strlen(trim($_UserLogin));
			$_NumCharPassword = strlen($_UserPassword);
			$_MessageText = "";
			$_ReturnValue = True;

			// Установка значений свойств объекта для входа в систему
			// И проверка валидности пары Логин, пароль
			if ($_NumCharLogin !== 0)
				$this->setUserLogin(trim($_UserLogin));
			else {
				$_MessageText = "Не указано 'Имя входа'(Логин)";
				$_ReturnValue = False;
			}
// !!!!!!!   Временно отключил проверку пароля
			$this->setUserPassword($_UserPassword);
/*			if ($_NumCharPassword !== 0)
				$this->setUserPassword($_UserPassword);
			else {
				$_MessageText = "Не указан пароль";
				$_ReturnValue = False;
			}
*/

			if ($_NumCharLogin === 0 && $_NumCharPassword === 0) {
				$_MessageText = "Не указаны пара 'Имя входа'(Логин) и пароль";
				$_ReturnValue = False;
			}

			// При необходимости Запомнить сообщение в объекте сообщений
			if (!$_ReturnValue && strlen($_MessageText) <> 0) {
					$All_Message->Add_Message("Объект 'Пользователь'", $_MessageText, 0, "Пользователь");
					$_MessageText = "";
			}

			if ($_ReturnValue && isset($Arr_Sess)){
				$All_Message->Add_Message("Объект 'Пользователь'", "Контроль введенных значений", 0, "Разработчик");
				$_ReturnValue = $this->ControlData($All_Message, $Arr_Sess);
			}

			// При прохождении всех проверок выполнить чтение данных
			if ($_ReturnValue) {				$All_Message->Add_Message("Объект 'Пользователь'", "Считывание данных пользователя", 0, "Разработчик");
				$_ReturnValue = $this->readUserData($MainConnect, $SystemValue, $All_Message, 0);
			}
			else {
				$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка обработки данных. Выполните вход позже", 0, "Пользователь");
				$_ReturnValue = False;
			}

			if ($_ReturnValue && isset($Arr_Sess))
				$this->UpdateData($Arr_Sess);

			// уничтожение внутренних переменных
			unset($_NumCharLogin, $_NumCharPassword, $_MessageText);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getCategory()
	### 	- получить категории пользователя
		Function getCategory() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Array 	- массив, содержащий категории пользователя или False, если таковых нет
	###
			$_ReturnValue = False;
			if (count($this->_Array_UserCategory) !== 0)
				$_ReturnValue = $this->_Array_UserCategory;

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getEMail()
	### 	- получить адреса электронной почты пользователя
		Function getEMail() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Array 	- массив, содержащий адреса электронной почты пользователя или False, если таковых нет
	###
			$_ReturnValue = False;
			if (count($this->_Array_EMail) !== 0)
				$_ReturnValue = $this->_Array_EMail;

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### saveUser(Object Connection, Object ErrorOfModul, object SystemConfig, Array UserData)
	### 	- создать нового пользователя системы
		Function saveUser($MainConnect, $All_Message, $SystemValue, $Arr_UserData) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  object SystemConfig		- Данные сессии пользователя
	###  Array Arr_UserData			- Новые значения пользовательских данных
	###------- Выходные параметры
	###	Bool	- признак удачного выполнения функции
	###

			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {
				// выполнение из приложения 1С
				$_ReturnValue = $this->saveUserToBase1CMetod($MainConnect, $All_Message, $SystemValue, $Arr_UserData);
			} Else {
				// выполнение внутренними методами
	        	$_ReturnValue = $this->saveUserToBase($MainConnect, $All_Message, $SystemValue, $Arr_UserData);
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### createNewUser(Object Connection, Object ErrorOfModul, String Login, String HASH Password, String EMAil, object SystemConfig, Bool UseAllNumber)
	### 	- создать нового пользователя системы
		Function createNewUser($MainConnect, $All_Message, $_UserLogin, $_UserPassword, $_UserEMail, $_UseSubsribeNews, $SystemValue, $UseAllNumber) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  String Login				- Login пользователя в БД
	###  String HASH Password		- пароль пользователя
	###  String EMail				- регистрируемый адрес электронной почты
	###  object SystemConfig		- данные сессии пользователя
	###  UseAllNumber				- признак использования пропущенных и помеченных на удаление ID
	###------- Выходные параметры
	###	Bool	- признак удачного выполнения функции
	###
			$_ReturnValue = True;

			$this->_B_UserNew = True;
			if (!$this->setUserLogin($_UserLogin))
				$_ReturnValue = False;
			if (!$this->setUserPassword($_UserPassword))
				$_ReturnValue = False;
			$this->_B_UserActive = True;
			$this->_B_SubscribeNews = $_UseSubsribeNews;
			$i = count($this->_Array_EMail) / 8;
			$D_DateConfirm = date("Y-m-d H:i:s"); // new DateTime();
			$S_DateConfirm = (string)$D_DateConfirm; //$D_DateConfirm->format('Y-m-d H:i:s');
			if (!$this->setUserEMail($_UserEMail, $this->_Array_EMail[$i]["Адрес"]))
				$_ReturnValue = False;
			$this->_Array_EMail[$i]["Подтвержден"] = False;
			$this->_Array_EMail[$i]["Основной"] = True;
			$this->_Array_EMail[$i]["Новый"] = True;
			$this->_Array_EMail[$i]['ДатаРегистрации'] = $D_DateConfirm;
			$this->_Array_EMail[$i]['ДатаПодтверждения'] = Null;
			$this->_Array_EMail[$i]['ДатаСтрокиПодтверждения'] = $D_DateConfirm;
			$this->_Array_EMail[$i]['СтрокаПодтверждения'] = ""; $this->createConfirmEMailText($S_EMail, $S_DateConfirm);
			//$this->_Array_UserCategory[count($this->_Array_UserCategory)] = "Зарегистрированный";
			$this->_Array_UserCategory[count($this->_Array_UserCategory)] = "Registered";

			unset($D_DateConfirm, $S_DateConfirm);

			if ($_ReturnValue) {
				if ($MainConnect->Boo_Use1CManager == True) {
					// заполнение из базы 1С
					$_ReturnValue = $this->saveUserToBase1CMetod($MainConnect, $All_Message, $SystemValue);
				} else {
					$_ReturnValue = $this->saveNewUserToBase($MainConnect, $All_Message, $SystemValue, $UseAllNumber);
				}
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	FindCategory(String Category)
	###		- найти в массиве категорий необходимую категорию
		Function FindCategory($S_Category){
	###------- Входные параметры
	###  String S_Category				- искмая категория у пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного поиска
	###
			$_ReturnValue = False;
			// проверка массива на количество элементов
			if (is_array($this->_Array_UserCategory) && count($this->_Array_UserCategory) > 0) {
				// цикл по всем категориям сотрудника
				foreach ($this->_Array_UserCategory as $Value) {
					// если значение найдено, прервать цикл и признак поиска в истино
					if ($Value === $S_Category) {
						$_ReturnValue = True;
						Break;
					}
				}
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### updateUserServices(Object Connection, Object ErrorOfModul, Object SystemConfig, Array Arr_Data)
	###		- инициировать изменение данных пользователя через сервис обслуживания
		Function updateUserServices($MainConnect, $All_Message, $SystemValue, $Arr_Data) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Object SystemConfig		- данные сессии пользователя
	###  Array Arr_Data				- массив параметров для отправки подтверждения на адрес электронной почты
	###------- Выходные параметры
	###  Bool 	- признак удачной операции по отправке подтверждения на адрес электронной почты
	###

			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {
				// выполнение из приложения 1С
				$_ReturnValue = $this->updateDataUser1CMethod($MainConnect, $All_Message, $SystemValue, $Arr_Data);
			} Else {
				// выполнение внутренними методами
	        	$_ReturnValue = $this->updateDataUserPHPMethod($MainConnect, $All_Message, $SystemValue, $Arr_Data);
			}

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getConfirmEMailText(Object Connection, Object ErrorOfModul, Object SystemConfig, String S_EMail, String S_DateConfirm)
	###		- сгенерировать код подтверждения адреса EMail
		Function getConfirmEMailText($MainConnect, $All_Message, $SystemValue, $S_EMail, $S_DateConfirm) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Object SystemConfig		- данные сессии пользователя
	###  String S_EMail				- адрес электронной почты
	###  String S_DateConfirm		- дата подтверждения регистрации электронной почты
	###------- Выходные параметры
	###  String 	- вычисленный код, который используется для подтверждения указанного EMail
	###

			$_ReturnValue = "";

			Foreach ($this->_Array_EMail as $Value) {				If ($Value['Адрес'] = $S_EMail) {					If (strlen($Value['СтрокаПодтверждения']) == 0) {						$TextConfirm = $this->createConfirmEMailText($S_EMail, $S_DateConfirm);
						If ($this->updateConfirmEMailText($MainConnect, $All_Message, $SystemValue, $S_EMail, $S_DateConfirm, $TextConfirm))
							$_ReturnValue = $TextConfirm;
						unset($TextConfirm);
					}
					Else
						$_ReturnValue = $Value['СтрокаПодтверждения'];
					Break;				}			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	readAllImageUrl(Object Connection, Object ErrorOfModul, Object DataSession)
	###		- инициировать чтение доступных ссылок на графические объекты пользователя
		Function readAllImageUrl($MainConnect, $SystemValue, $All_Message) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###

    	$_ReturnValue = $this->ReadImageUrlsFromBase($MainConnect, $SystemValue, $All_Message);

    	Return $_ReturnValue;
	}

	###////// Открытые текущего проекта

	###@@@@@@@@@@@@@@@@@@@@@
	### getBanersList()
	### 	- вернуть значение свойства объекта
		Function getBanersList() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  String 	- значение свойства ID
	###
			return $this->_Arr_Baners;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getBanersList(Object Connection, Object ErrorOfModul, Object DataSession)
	### 	- получить массив объектов банеров принадлежащих пользователю
		Function readBanersList(&$MainConnect, &$SystemValue, $All_Message, $Arr_Params) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  bool 	- признак удачной операции
	###

			$_ReturnValue = $this->ReadBanersListFromBase($MainConnect, $SystemValue, $All_Message, $Arr_Params);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###////// Внутренние

	###@@@@@@@@@@@@@@@@@@@@@
	### ReadImageUrlsFromBase(Object Connection, Object ErrorOfModul, Object DataSession)
	### 	- прочитать графические объекты текущего пользователя
		private function ReadImageUrlsFromBase($MainConnect, $SystemValue, $All_Message) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {
				// заполнение из базы 1С
				$_ReturnValue = $this->readImageUrls1CWebMetod($MainConnect, $SystemValue, $All_Message);
			}
            Else {
				$SQL_Query = "SELECT `ID`, `HTTPLink`, `IndexImg` FROM `tableuserlinks` WHERE `UserID` = '" . $this->_S_UserId . "'";

				If ($Result = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query)) {

					$n_index = 0;
					While ($Row = $Result->fetch_row()) {
						$O_ImageLink = New ImageLink($Row[0]);
						$O_ImageLink->_S_LinkAdress = $Row[1];
						$O_ImageLink->_I_IndexImg = $Row[2];
						$O_ImageLink->_S_UserId = $this->_S_UserId;
						$this->_Arr_UserImgLinks[$n_index] = $O_ImageLink;
						$n_index++;
					}
					unset($n_index, $Result);
					If (isset($O_ImageLink))
						unset($O_ImageLink);
					If (isset($Row))
						unset($Row);

				}
				Else {					$_ReturnValue = False;
				}
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readImageUrls1CWebMetod(Object Connection, Object ErrorOfModul, Object DataSession)
	### 	- прочитать графические объекты текущего пользователя Web методом 1С
		private function readImageUrls1CWebMetod($MainConnect, $SystemValue, $All_Message) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###

			$_ReturnValue = True;

			$All_Message->Add_Message("Объект 'Пользователь'", "Начало получения данных о графических объектах", 0, "Разработчик");

			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/ws/PortalMaintenance.1cws?wsdl';

			$_ReturnValue = $MainConnect->setConnection($All_Message);

			$Result = NULL;
			If ($_ReturnValue) {
				Try {
					$data = array (
							"ИдентификаторПользователя"	=> $this->_P_ID  // Идентификатор пользователя, что бы отобрать только порталы этого пользователя
						);
					$JSONData = json_encode($data, JSON_UNESCAPED_UNICODE);
					$_paramMethod = array (
							"CodePortal" => Str_PortalIdent,
							"Parameters" => $JSONData
						);

					$HTTPConnection = $MainConnect->ConnectDB;
					$Result = $HTTPConnection->GetImageUrlsInfo($_paramMethod)->return;
				} Catch(Exception $e) {
					$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка обращения к методу 'GetImageUrlsInfo()' WEB сервиса '" . $MainConnect->Str_HTTPWSAdress . "'. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
					$MainConnect->insertLogMessage($All_Message ,$e->getMessage());
					$_ReturnValue = False;
					$Result = NULL;
				}
			}
			$MainConnect->Str_HTTPWSAdress = "";

			If ($Result !== NULL && is_object($Result)) {
				If (isset($Result->Error) && $Result->Error == False) {
					$ArrResult = json_decode($Result->Result, True)['#value'];
					If (is_array($ArrResult)) {
		 				$Num_Row = 0;
						Foreach($ArrResult As &$Value) {
							$O_ImageLink = New ImageLink($Value['SID']);
							$O_ImageLink->_S_LinkAdress = $Value['HTTPLink'];
							$O_ImageLink->_P_ID = $Value['PID'];
							$O_ImageLink->_I_IndexImg = $Value['Index'];
							$O_ImageLink->_S_UserId = $this->_S_UserId;
							$this->_Arr_UserImgLinks[$Num_Row] = $O_ImageLink;
							$Num_Row ++;
						}
						unset($Num_Row);
					} Else {
						$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка получения данных о графических объектах; метод 'GetImageUrlsInfo()' сервис '" . $MainConnect->Str_HTTPWSAdress . "'. Некорректные данные ответа", 0, "Разработчик");
					}
					unset($ArrResult);
				} Else {
					$All_Message->Log_GlobalError = True;
					If (isset($Result->ErrorMessage))
						$All_Message->Add_Message("Объект 'Пользователь'", $Result->ErrorMessage, 0, "Разработчик");
					$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка получения данных о графических объектах; метод 'GetImageUrlsInfo()' сервис '" . $MainConnect->Str_HTTPWSAdress . "'. Ошибка неизвестна", 0, "Разработчик");
				}
			} Else {
				$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка получения данных о графических объектах. Неизвестный ответ - метод 'GetImageUrlsInfo()' сервис '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
			}

			$All_Message->Add_Message("Объект 'Пользователь'", "Завершение получения данных о графических объектах", 0, "Разработчик");
			unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest, $_paramMethod);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### saveNewUserToBase(Object Connection, Object ErrorOfModul, Object SystemConfig, Array UserData)
	### 	- записать данные нового пользователя в БД
		private function saveUserToBase($MainConnect, $All_Message, $SystemValue, $Arr_UserData) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Object SystemConfig		- Данные сессии пользователя
	###  Array Arr_UserData			- Новые значения пользовательских данных
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = True;
 			$B_NeedSaveUser = False;
			$B_NeedSavePeople = False;
            $SQL_Query = "";

			if ($this->S_User_Nik <> $Arr_UserData["Ник"])
				$B_NeedSaveUser = True;
			if ($this->_B_SubscribeNews <> $Arr_UserData["Подписка"])
				$B_NeedSaveUser = True;

			if ($this->_S_FirstName <> $Arr_UserData["Имя"])
				$B_NeedSavePeople = True;
			if ($this->_S_SecondName <> $Arr_UserData["Отчество"])
				$B_NeedSavePeople = True;
			if ($this->_S_LastName <> $Arr_UserData["Фамилия"])
				$B_NeedSavePeople = True;
			if ($this->_B_SexMen <> $Arr_UserData["Пол"])
				$B_NeedSavePeople = True;

			if ($B_NeedSaveUser) {				$SQL_Query = "UPDATE `UsersSys` SET `UserNick` = '" . $MainConnect->ConnectDB->real_escape_string($Arr_UserData["Ник"])
					. "', `SubscribeNews` = '" . ($Arr_UserData["Подписка"] ? "1": "0")
					. "' WHERE `ID` = '" . $this->_S_UserId . "'";			}

			if ($B_NeedSavePeople) {
				if (strlen($SQL_Query) > 0)
					$SQL_Query .= "; ";
				$SQL_Query .= "UPDATE `peoplelist` SET `FirstName` = '" . $MainConnect->ConnectDB->real_escape_string($Arr_UserData["Имя"])
					. "', `SecondName` = '" . $MainConnect->ConnectDB->real_escape_string($Arr_UserData["Отчество"])
					. "', `LastName` = '" . $MainConnect->ConnectDB->real_escape_string($Arr_UserData["Фамилия"]) . "', `Sex` = '" . ($Arr_UserData["Пол"] ? "1": "0")
					. "' WHERE `ID` = '" . $this->getPeopleID() . "'";
			}

			$MainConnect->ConnectDB->autocommit(False);				// отмена авто подтверждения запросов/транзакций
//					if (PHP_VERSION_ID >= 50500)
			$MainConnect->ConnectDB->begin_transaction();

			$_ReturnValue = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query, True);
			if ($_ReturnValue)
				$MainConnect->ConnectDB->commit();
			else
				$MainConnect->ConnectDB->rollback();
			$MainConnect->ConnectDB->autocommit(True);				// установка авто подтверждения запросов/транзакций

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### saveUserToBase1CMetod(Object Connection, Object ErrorOfModul, Array SystemConfig, Array Arr_UserData)
	### 	- записать данные пользователя в БД 1С
		private function saveUserToBase1CMetod($MainConnect, $All_Message, $SystemValue, $Arr_UserData = NULL) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array SystemConfig			- данные сессии пользователя
	###  Array Arr_UserData			- Новые значения пользовательских данных
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = True;

			//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
			//	http://localhost/ManagerPortals/hs/UsersMaintenanceService/UserLogin/ROP00000000000000002/
			If ($this->_P_ID == ""){
				$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/UsersMaintenanceService/UserLogin/' . Str_PortalIdent . '/';
			} Else {				$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/UsersMaintenanceService/UserInfo/' . Str_PortalIdent . '/' . $this->_P_ID . '/';
			}

			If ($Arr_UserData == NULL) {
				$data = array (
					"Логин" => $this->_S_UserLogin,
					"Ник" => $this->S_User_Nik,
					"Подписка" => $this->_B_SubscribeNews,
					"Фамилия" => $this->_S_LastName,
					"Имя" => $this->_S_FirstName,
					"Отчество" => $this->_S_SecondName,
					"Пол" => $this->_B_SexMen,
					"Пароль" => $this->_S_UserPassword,
					"ИзменитьПароль" => False,
					"ЮрФизЛицо" => 1,                    // 0 - юридическое лицо; 1 - физическое лицо
					"ВидКонтрагента" => 0,               // 0 - юридическое лицо; 1 - Физическое лицо; 2- Юридическое не резидент; 3 - Индивидуальный предприниматель
					"ИспользоватьКуки" => $this->_B_UseCookies,
					"СогласиеСПолитикой" => True,
					"СогласиеСКонфиденциальностью" => True,
					"МассивЭлектронныхАдресов" => $this->_Array_EMail
				);
			} Else {
				$data = array (
					"Логин" => $this->_S_UserLogin,
					"ЮрФизЛицо" => 1,
					"ВидКонтрагента" => 0,
					"СогласиеСПолитикой" => $this->$_B_UserAgreePolicyData,
					"СогласиеСКонфиденциальностью" => $this->_B_UserAgreeConfData
				);
				If (isset($Arr_UserData["Ник"])) {
					$data["Ник"] = $Arr_UserData["Ник"];
				}
				If (isset($Arr_UserData["Фамилия"])) {
					$data["Фамилия"] = $Arr_UserData["Фамилия"];
				}
				If (isset($Arr_UserData["Имя"])) {
					$data["Имя"] = $Arr_UserData["Имя"];
				}
				If (isset($Arr_UserData["Отчество"])) {
					$data["Отчество"] = $Arr_UserData["Отчество"];
				}
				If (isset($Arr_UserData["Пол"])) {
					$data["Пол"] = $Arr_UserData["Пол"];
				}
				If (isset($Arr_UserData["Подписка"])) {
					$data["Подписка"] = $Arr_UserData["Подписка"];
				}
				If (isset($Arr_UserData["ИзменитьПароль"])) {
					$data["ИзменитьПароль"] = $Arr_UserData["ИзменитьПароль"];
					$data["Пароль"] = $Arr_UserData["Пароль"];
				} Else {
					$data["ИзменитьПароль"] = False;
				}
				//	"ИспользоватьКуки" => $this->_B_UseCookies,
				If (isset($Arr_UserData["ИспользоватьКуки"])) {
					$data["ИспользоватьКуки"] = $Arr_UserData["ИспользоватьКуки"];
				}
				//	"МассивЭлектронныхАдресов" => $this->_Array_EMail
				If (isset($Arr_UserData["МассивЭлектронныхАдресов"])) {
					$data["МассивЭлектронныхАдресов"] = $this->_Array_EMail;
				}
			}

			$JSONData = json_encode($data, JSON_UNESCAPED_UNICODE);

			If ($this->_P_ID == ""){
				$HTTPRequest = "POST";
			} Else {
				$HTTPRequest = "PUT";
			}
			$HTTPHeader = array('Content-Type: application/json',
							'Content-Language: ru-RU');

			$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest, $JSONData);

			If ($Result !== NULL) {

				If ($Result['Ошибка'] == True) {
					$_ReturnValue = False;
					$All_Message->Add_Message("Объект 'Пользователь'", $Result['ОписаниеОшибки'], 0, "Разработчик");
					$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка в работе сайта. Выполните операцию позже", 0, "Пользователь");
				} Else {
					$ArrResult = $Result['Результат'];
					If (is_array($ArrResult)) {
						Foreach($ArrResult As $Value) {
							$Argument = $Value['Наименование'];
							$ValueArg = $Value['Значение'];

							$this->setValueClassVar($Argument, $ValueArg);
						}
						unset($Argument, $ValueArg);
					}
					unset($ArrResult);
				}
			}
			$MainConnect->Str_HTTPWSAdress = "";
			unset($Result, $HTTPHeader, $HTTPRequest, $JSONData, $data);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### saveNewUserToBase(Object Connection, Object ErrorOfModul, Array SystemConfig, Bool Value)
	### 	- записать данные нового пользователя в БД
		private function saveNewUserToBase($MainConnect, $All_Message, $SystemValue, $UseAllNumber) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array SystemConfig			- данные сессии пользователя
	###  UseAllNumber				- признак использования пропущенных и помеченных на удаление ID
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = True;

			// проверка на существование пользователя с данными нового пользователя
			if ($this->_B_UserNew) {				// Заблокирую таблицы, что бы избежать коллизий при добавлении новых пользователей
				$SQL_Query = "LOCK TABLES userssys WRITE, tableemailusers WRITE, peoplelist WRITE, usercategoryins WRITE, categorylist WRITE";
				if (!$MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query)) {
					$_ReturnValue = False;
				}

				$SQL_Query = "";
				if ($_ReturnValue) {
					$SQL_Query .= "SELECT `ID` FROM `userssys` WHERE `loginuser` = '" . $MainConnect->ConnectDB->real_escape_string($this->_S_UserLogin) . "'; ";
					$SQL_Query .= " SELECT `ID` FROM `tableemailusers` WHERE `adressemail` = '" . $MainConnect->ConnectDB->real_escape_string($this->_Array_EMail[0]["Адрес"]) . "'";

					$Num_Result = 0;
					if ($MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query, True)) {
						do {
							// получаем результирующий набор
							if ($Result = $MainConnect->ConnectDB->store_result()) {
								// Обработка пакетов с данными пользователя
								$Row_Count = $Result->num_rows;
								if ($Row_Count !== 0) {									$_MessageText = "";
									$_ReturnValue = False;
									if ($Num_Result === 0) {
										$All_Message->Add_Message("Регистрация", "Пользователь с указанным Логином уже зарегистрирован в системе. Выберите другой", 0, "Пользователь", 0, "", "", "new_username");
										$_MessageText = "";
									}
									elseif ($Num_Result === 1) {										$All_Message->Add_Message("Регистрация", "Указанный адрес электронной почты уже зарегистрирован в системе. Укажите другой", 0, "Пользователь", 0, "", "", "new_user_mail");
										$_MessageText = "";
									}
									// нет смысла добавлять пустое сообщение
									if (strlen($_MessageText) > 0)
										$All_Message->Add_Message("Регистрация", $_MessageText, 0, "Разработчик");

									unset($_MessageText);
								}
								// освобождение переменных
								$Result->free();
								if (isset($Row_Count))
									unset($Row_Count);
							}
							// увеличиваю счетчик результата запроса
							if ($MainConnect->ConnectDB->more_results()) $Num_Result ++;
						} while ($MainConnect->ConnectDB->more_results() && $MainConnect->ConnectDB->next_result());
						unset($Num_Result);
					}

					// Формирование запроса для добавления пользователя
					$Arr_SQL_Query = array();
					$SQL_Query = "";
					$NewIDTable = "";
					$IDTable = "";
					$Arr_FindValue = array();

					// добавление записи в таблицу пользователей
					if ($_ReturnValue) {
						If (!$NewIDTable = $MainConnect->matchNewIDRecord($All_Message, "ФИО", $UseAllNumber, $SystemValue))
							$_ReturnValue = False;
						else {
							$this->setPeopleID($NewIDTable);
							$Arr_SQL_Query[count($Arr_SQL_Query)] = "INSERT INTO `peoplelist` (`ID`, `FirstName`, `SecondName`, `LastName`, `Sex`) VALUES ('"
								. $this->getPeopleID() . "', '', '', '', '0')";
						}
					}

					// добавление записи в таблицу пользователей
					if ($_ReturnValue) {						If (!$NewIDTable = $MainConnect->matchNewIDRecord($All_Message, "Пользователи приложения", $UseAllNumber, $SystemValue))							$_ReturnValue = False;
						else {
							$this->_S_UserId = $NewIDTable;
							$Arr_SQL_Query[count($Arr_SQL_Query)] = "INSERT INTO `userssys` (`ID`, `LoginUser`, `UserPassword`, `UserNick`, `IDPeople`, `SubscribeNews`) VALUES ('"
								. $this->_S_UserId . "','" . $MainConnect->ConnectDB->real_escape_string($this->_S_UserLogin) . "', '" . $this->_S_UserPassword . "', '', '" . $this->getPeopleID()
								. "', '" . (($this->_B_SubscribeNews) ? "1" : "0") . "')";
						}
					}

					// добавление записи в таблицу категорий
					if ($_ReturnValue) {
						If (!$NewIDTable = $MainConnect->matchNewIDRecord($All_Message, "Установленные категории", $UseAllNumber, $SystemValue)) {
							$_ReturnValue = False;
						}
						else {
							$Arr_FindValue[0]["Поле"] = "namecat";
							$Arr_FindValue[0]["Значение"] = $this->_Array_UserCategory[0];
							$IDTable = $MainConnect->getIDRecord($All_Message, "Категории", $Arr_FindValue, $SystemValue);
							if ((is_bool($IDTable) && $IDTable === False) || strlen($IDTable) == 0)
								$_ReturnValue = False;
							else
								$Arr_SQL_Query[count($Arr_SQL_Query)]= "INSERT INTO `usercategoryins` (`ID`, `IDUser`, `Category`, `DateRegister`) VALUES ('"
									. $NewIDTable . "','" . $this->_S_UserId . "', '" . $IDTable . "', '" . date("Y-m-d H:i:s") . "')";
						}
					}

					// добавление записи в таблицу электронных адресов
					if ($_ReturnValue) {
						If (!$NewIDTable = $MainConnect->matchNewIDRecord($All_Message, "Адреса электронной почты", $UseAllNumber, $SystemValue)) {
							$_ReturnValue = False;
						}
						else {
							$i = count($Arr_SQL_Query);
							$Arr_SQL_Query[$i]= "INSERT INTO `tableemailusers` (`ID`, `AdressEMail`, `IDUser`, `Confirm`, `Main`, `DateConfirm`, `ConfirmText`, `ConfirmTextDate`) VALUES ('"
								. $NewIDTable . "', '" . $MainConnect->ConnectDB->real_escape_string($this->_Array_EMail[0]['Адрес']) . "','" . $this->_S_UserId . "', '"
								. ($this->_Array_EMail[0]['Подтвержден'] ? "1" : "0") . "', '" . ($this->_Array_EMail[0]['Основной'] ? "1" : "0")
								. "', NULL, '" . $this->_Array_EMail[0]['СтрокаПодтверждения'] . "', '" . $this->_Array_EMail[0]['ДатаСтрокиПодтверждения'] . "')";
						}
					}

					unset($NewIDTable, $IDTable, $Arr_FindValue);

					// выполнение сформированного запроса
					if ($_ReturnValue) {
						$MainConnect->ConnectDB->autocommit(False);				// отмена авто подтверждения запросов/транзакций
	//					if (PHP_VERSION_ID >= 50500)
							$MainConnect->ConnectDB->begin_transaction();

						for ($i = 0; $i < count($Arr_SQL_Query); $i++){
							$SQL_Query = $Arr_SQL_Query[$i];
							$Result = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query);
							if (!$Result) {								$_ReturnValue = False;
								Break;							}
						}

						if ($_ReturnValue)
							$MainConnect->ConnectDB->commit();
						else
							$MainConnect->ConnectDB->rollback();
						$MainConnect->ConnectDB->autocommit(True);				// установка авто подтверждения запросов/транзакций

/*
					$mess_mail = "<html><head><title>Ссылка для активации адреса сайта.</title></head><body>\n";
					$mess_mail .= "<p>Добрый день! На сайте 'Российская палитра' был зарегистрирован аккаунт с указанием Вашего электронного почтового ящика.<br>\n";
					$mess_mail .= "Для активации аккаунта в системе перейдите по ссылке указанной ниже. Если Вы не желаете активировать аккаунт, можете удалить письмо без перехода по ссылке или проигнорировать данное сообщение.<br><br>\n";
					$mess_mail .= "<a title = \"Российская палитра. Активация аккаунта.\" target = \"_blank\" href = \"http://".Host.Put_File."/".File_Nachalo."?actvate=".$Hash_Temp."\">Российская палитра. Активация аккаунта для пользователя '".$Safe_stroka."'.</a><br><br>\n";
					$mess_mail .= "Благодарим Вас за регистрацию на нашем сайте. Надеемся наш проект поможет Вам в поиске необходимой информации.\n";
					$mess_mail .= "Администрация сайта 'Российская палитра'.</p>\n";
					$mess_mail .= "</body></html>";
					$head_mail = "MIME-Version: 1.0 \r\n Content-type: text/html; charset=windows-1251 \r\n";
					$head_mail .= "From: ".Mail_robot."\r\n";
//					$head_mail .= "Bcc: moderator@localhost\r\n";
					$Send_m = true;
//					$Send_m = mail($Arr_Temp[3],"Активация аккаунта.", $mess_mail, $head_mail);
*/
					}
				}
				// Разблокирую таблицы
				$SQL_Query = "UNLOCK TABLES";
				$MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query);
			}

			unset($SQL_Query);
			if (isset($i))
				unset($i);
			if (isset($Arr_SQL_Query))
				unset($Arr_SQL_Query);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### createConfirmEMailText(String S_EMail)
	###		- сгенерировать код подтверждения адреса EMail
		private function createConfirmEMailText($S_EMail, $S_DateConfirm) {	###------- Входные параметры
	###  String S_EMail				- адрес электронной почты
	###  String S_DateConfirm		- дата регистрации электронной почты
	###------- Выходные параметры
	###  String 	- сгенерированный код, который используется для подтверждения
	###

			$_ReturnValue = "";

			$_ReturnValue = Hash("md5", $S_EMail . " - " . $S_DateConfirm);

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### createConfirmEMailText(Object Connections, Object ErrorOfModul, Object SystemConfig, String Value, String Value, String Value)
	###		- сгенерировать код подтверждения адреса EMail
		private function updateConfirmEMailText($MainConnect, $All_Message, $SystemValue, $S_EMail, $S_DateConfirm, $S_TextConfirm) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Object SystemConfig		- данные сессии пользователя
	###  String S_EMail				- адрес электронной почты
	###  String S_DateConfirm		- дата регистрации электронной почты
	###  String S_TextConfirm		- текст подтверждения электронной почты
	###------- Выходные параметры
	###  String 	- сгенерированный код, который используется для подтверждения
	###

			$_ReturnValue = true;
 			$Str_DBName = "Личный кабинет";
			if (strlen($S_EMail) == 0 || strlen($S_TextConfirm) == 0)
				$_ReturnValue = false;
			else {
				//Доработать проверку  существования текста подтверждения и записать логи, в случае некорректного
				$SQL_Query = "SELECT `AdressEMail`, `Confirm`, `ConfirmText`, `ConfirmTextDate`"
					. " FROM `tableemailusers` WHERE `IDUser` = '" . $this->_S_UserId . "' AND `AdressEMail` = '" . $MainConnect->ConnectDB->real_escape_string($S_EMail)
					. "' AND `Confirm` = '0'";
				if ($Result = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query)) {
					if ($Result->num_rows == 0) {
 						$Message = "Неудачная попытка подтверждения адреса электронной почты: '" . $S_EMail;
						$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", 0);
						$MainConnect->insertLogMessage($All_Message, $Message, $SystemValue);
						$_ReturnValue = false;
					}
					else{
						$SQL_Query = "UPDATE `tableemailusers` SET `ConfirmText` = '" . $S_TextConfirm . "', `DateConfirm` = NULL,  `ConfirmTextDate` = '" . date("Y-m-d H:i:s")
							. "' WHERE `tableemailusers`.`IDUser` = '" . $this->_S_UserId . "' AND `tableemailusers`.`AdressEMail` = '" . $MainConnect->ConnectDB->real_escape_string($S_EMail)
							. "' AND `tableemailusers`.`Confirm` = '0'";
						//if (!$_ReturnValue = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query)) {
						$_ReturnValue = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query);
					}
				}
				else{
					$Message = "Ошибка выполнения запроса: '" . $SQL_Query . "' - '" . $MainConnect->error . "'";
					$All_Message->add_Message($Str_DBName, $Message, 2, "Разработчик", $MainConnect->errno);
					$MainConnect->insertLogMessage($All_Message, $Message, $SystemValue);
					$_ReturnValue = false;
				}
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readUserData(Object Connection, Object ErrorOfModul, Integer Metod)
	###		- прочитать данные пользователя из БД, функция заполняет прочитанными из БД значениями свойства класса
		private function readUserData($MainConnect, $SystemValue, $All_Message, $_I_MetodRead) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object SystemConfig		- данные сессии пользователя
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Integer Metod				- Метод чтения данных
	###------- Выходные параметры
	###  Bool 	- признак удачного чтения данных
	###
			$_ReturnValue = True;

			if ($MainConnect->Boo_Use1CManager == True) {				// заполнение из базы 1С				$_ReturnValue = $this->readUserData1CMetod($MainConnect, $SystemValue, $All_Message, $_I_MetodRead);
			} else {
				// заполнение из базы MySQL
				$Num_Result = 0;
				$Row_Count = 0;
				$SQL_Query = "";
/*
SELECT * FROM `userssys` WHERE `LoginUser` = 'User11' AND `UserPassword` = ''

SELECT `UsersSys`.`ID`, `UsersSys`.`UserNick`, `ManagerUser`.`UserActive`,
`ManagerUser`.`DateRegister`, `ManagerUser`.`DateActive`,`UsersBlock`.`BlockUser`,
`UsersBlock`.`DateBlock`, `UsersBlock`.`DateUnBlock`, `UsersBlock`.`MotiveBlock` FROM `UsersSys`
LEFT JOIN `ManagerUser` ON `UsersSys`.`ID` = `ManagerUser`.`IDUser`
LEFT JOIN `UsersBlock` ON `UsersSys`.`ID` = `UsersBlock`.`IDUser`
WHERE `UsersSys`.`LoginUser` = 'User01' AND `UsersSys`.`UserPassword` = ''

SELECT `UsersSys`.`ID`, `UsersSys`.`UserNick`, `ManagerUser`.`UserActive`,
`ManagerUser`.`DateRegister`, `ManagerUser`.`DateActive`,`UsersBlock`.`BlockUser`,
`UsersBlock`.`DateBlock`, `UsersBlock`.`DateUnBlock`, `UsersBlock`.`MotiveBlock`,
`MotivesBlocks`.`NameBlock`, `PeopleList`.`ID` AS 'PeopleID', `PeopleList`.`FirstName`,
`PeopleList`.`SecondName`, `PeopleList`.`LastName`, `PeopleList`.`Sex`
FROM `UsersSys`
LEFT JOIN `ManagerUser` ON `UsersSys`.`ID` = `ManagerUser`.`IDUser`
LEFT JOIN `UsersBlock` ON `UsersSys`.`ID` = `UsersBlock`.`IDUser`
LEFT JOIN `PeopleList` ON `UsersSys`.`IDPeople` = `PeopleList`.`ID`
LEFT JOIN `MotivesBlocks` ON `UsersBlock`.`MotiveBlock` = `MotivesBlocks`.`ID`
WHERE `UsersSys`.`LoginUser` = 'User01' AND `UsersSys`.`UserPassword` = ''

SELECT `CategoryList`.`NameCat` AS 'Category' FROM `UsersSys`
INNER JOIN `UserCategoryIns` ON `UsersSys`.`ID` = `UserCategoryIns`.`IDUser`
INNER JOIN `CategoryList` ON `UserCategoryIns`.`Category` = `CategoryList`.`ID`
WHERE `UsersSys`.`LoginUser` = 'User10' ORDER BY `Privilegies`
*/
				//$SQL_Query = "SELECT `ID` AS 'IDUser', `UserNik` AS 'NikName' FROM `UserSys` " .
				//	" WHERE `UserLogin` = '" . $this->_S_UserLogin . "' AND `UserPassword` = '" . $this->_S_UserPassword . "'";

				// Подзапрос для считывания данных пользователя
				$SQL_Query = "SELECT `UsersSys`.`ID`, `UsersSys`.`LoginUser`, `UsersSys`.`UserNick`, `UsersSys`.`SubscribeNews`, `ManagerUser`.`UserActive`, " .
						"`ManagerUser`.`DateRegister`, `ManagerUser`.`DateActive`,`UsersBlock`.`BlockUser`, " .
						"`UsersBlock`.`DateBlock`, `UsersBlock`.`DateUnBlock`, `UsersBlock`.`MotiveBlock`, " .
						"`MotivesBlocks`.`NameBlock`, `PeopleList`.`ID` AS 'PeopleID', `PeopleList`.`FirstName`, " .
						"`PeopleList`.`SecondName`, `PeopleList`.`LastName`, `PeopleList`.`Sex` " .
						"FROM `UsersSys` " .
						"LEFT JOIN `ManagerUser` ON `UsersSys`.`ID` = `ManagerUser`.`IDUser` " .
						"LEFT JOIN `UsersBlock` ON `UsersSys`.`ID` = `UsersBlock`.`IDUser` " .
						"LEFT JOIN `PeopleList` ON `UsersSys`.`IDPeople` = `PeopleList`.`ID` " .
						"LEFT JOIN `MotivesBlocks` ON `UsersBlock`.`MotiveBlock` = `MotivesBlocks`.`ID` " .
						"WHERE `UsersSys`.`";
				if ($_I_MetodRead === 0)
					$SQL_Query .= "LoginUser` = '" . $MainConnect->ConnectDB->real_escape_string($this->_S_UserLogin) .  "' AND `UsersSys`.`UserPassword` = '" . $this->_S_UserPassword;
				elseif  ($_I_MetodRead === 1)
					$SQL_Query .= "ID` = '" . $this->_S_UserId;

				// Подзапрос для считывания доступных категорий пользователя
				$SQL_Query .= "'
					;
					SELECT `CategoryList`.`NameCat` AS 'Category' FROM `UsersSys` " .
					"INNER JOIN `UserCategoryIns` ON `UsersSys`.`ID` = `UserCategoryIns`.`IDUser` " .
					"INNER JOIN `CategoryList` ON `UserCategoryIns`.`Category` = `CategoryList`.`ID` " .
					"WHERE `UsersSys`.`";
				if ($_I_MetodRead === 0)
					$SQL_Query .= "LoginUser` = '" . $MainConnect->ConnectDB->real_escape_string($this->_S_UserLogin) .  "' AND `UsersSys`.`UserPassword` = '" . $this->_S_UserPassword;
				elseif  ($_I_MetodRead === 1)
					$SQL_Query .= "ID` = '" . $this->_S_UserId;
				$SQL_Query.= "' ORDER BY `CategoryList`.`Privilegies`";

				// Подзапрос для считывания данных электронных адресов пользователя

				$SQL_Query .= "
					;
					SELECT `TableEMailUsers`.`AdressEMail` AS 'Adress', `TableEMailUsers`.`Confirm` AS 'Confirm', `TableEMailUsers`.`Main` AS 'Main', `TableEMailUsers`.`DateRegister` AS 'DateRegister', " .
					"`TableEMailUsers`.`DateConfirm` AS 'DateConfirm', `TableEMailUsers`.`ConfirmTextDate` AS 'ConfirmTextDate', `TableEMailUsers`.`ConfirmText` AS 'ConfirmText' FROM `UsersSys` ".
					"INNER JOIN `TableEMailUsers` ON `UsersSys`.`ID` = `TableEMailUsers`.`IDUser` ".
					"WHERE `UsersSys`.`";
				if ($_I_MetodRead === 0)
					$SQL_Query .= "LoginUser` = '" . $MainConnect->ConnectDB->real_escape_string($this->_S_UserLogin) .  "' AND `UsersSys`.`UserPassword` = '" . $this->_S_UserPassword;
				elseif  ($_I_MetodRead === 1)
					$SQL_Query .= "ID` = '" . $this->_S_UserId;
				$SQL_Query.= "' ORDER BY `TableEMailUsers`.`AdressEMail`";

###---------
//	$All_Message->add_Message("Пользователь", "SQL: '" . $SQL_Query . "'", 0, "Разработчик");
###---------
				if ($MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query, True)) {
					do {
						// получаем результирующий набор
						if ($Result = $MainConnect->ConnectDB->store_result()) {
							// Обработка пакетов с данными пользователя
							if ($Num_Result === 0) {
								// Информация о пользователе
								While ($Row = $Result->fetch_row()) {
									$Row_Count ++;
									if ($Row_Count === 1){
										// Читаем данные результата запроса только первой строки по объекту пользовател
										$this->_S_UserId 			= (string)$Row[0];
										$this->_S_UserLogin 		= (string)$Row[1];
										$this->S_User_Nik 			= stripslashes((string)$Row[2]);
										$this->_B_SubscribeNews 	= (bool)$Row[3];
										$this->_B_UserActive 		= (bool)$Row[4];
										$this->_B_UserBlock 		= (bool)$Row[7];
										$this->_S_MotiveBlockID 	= (string)$Row[10];
										$this->_S_MotiveBlock 		= (string)$Row[11];
										$this->setPeopleID((string)$Row[12]);
										$this->setPeopleName((string)$Row[13], (string)$Row[14], (string)$Row[15]);
										$this->_B_SexMen = (bool)$Row[16];
									}
								}

								if ($Row_Count === 0) {
									// В БД нет данных с этой парой Логин/Пароль
									$All_Message->Add_Message("Объект 'Пользователь'", "Пользователь с указанными данными не зарегистрирован в системе. Или неверно введены данные", 0, "Пользователь");
									$_ReturnValue = False;
								}
								elseif ($Row_Count > 1) {
									// В БД больше одного пользователя
									$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка обработки данных. Выполните вход позже", 0, "Пользователь");
									$All_Message->Add_Message("Объект 'Пользователь'", "Несколько объектов в базе с логином: ". addslashes($this->_S_UserLogin), 0, "Разработчик");
									$_ReturnValue = False;
								}
								if (isset($Row))
									unset($Row);
							}
							elseif ($Num_Result === 1) {
								// Назначенные категории пользователя
								$Num_Row = 0;
								While ($Row = $Result->fetch_row()) {
									$this->_Array_UserCategory[$Num_Row] = $Row[0];
									$Num_Row ++;
								}
								unset($Num_Row);
							}
							elseif ($Num_Result === 2) {
								// Назначенные категории пользователя
								$Num_Row = 0;
								While ($Row = $Result->fetch_row()) {
									$this->_Array_EMail[$Num_Row]['Адрес'] = (string)$Row[0];
									$this->_Array_EMail[$Num_Row]['Подтвержден'] = (bool)$Row[1];
									$this->_Array_EMail[$Num_Row]['Основной'] = (bool)$Row[2];
									$this->_Array_EMail[$Num_Row]['ДатаРегистрации'] = (string)$Row[3];
									$this->_Array_EMail[$Num_Row]['ДатаПодтверждения'] = (string)$Row[4];
									$this->_Array_EMail[$Num_Row]['ДатаСтрокиПодтверждения'] = (string)$Row[5];
									$this->_Array_EMail[$Num_Row]['СтрокаПодтверждения'] = (string)$Row[6];
									$Num_Row ++;
								}
								unset($Num_Row);
							}
							$Result->free();
						}
						/* увеличиваем счетчик результата запроса */
						if ($MainConnect->ConnectDB->more_results()) $Num_Result ++;

					} while ($MainConnect->ConnectDB->more_results() && $MainConnect->ConnectDB->next_result() && $_ReturnValue);
				}

				// уничтожение внутренних переменных
				if (isset($Row))
					unset($Row);
				if (isset($Result))
					unset($Result);
				unset($SQL_Query, $Row_Count, $Num_Result);
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### readUserData1CMetod(Object Connection, Object SystemConfig, Object ErrorOfModul, Integer Metod)
	###		- прочитать данные пользователя из БД 1С, функция заполняет прочитанными из БД 1С значениями свойства класса
		private function readUserData1CMetod($MainConnect, $SystemValue, $All_Message, $_I_MetodRead) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object SystemConfig		- данные сессии пользователя
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Integer Metod				- Метод чтения данных
	###------- Выходные параметры
	###  Bool 	- признак удачного чтения данных
	###
			$_ReturnValue = True;

			//	HTTP://<ИмяСервера>:порт>/<ИмяКонфигурации>/hs/<КорневойURL>/<Шаблон>
			//	http://localhost/ManagerPortals/hs/UsersMaintenanceService/UserLogin/ROP00000000000000002/
			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/UsersMaintenanceService/UserLogin/' . Str_PortalIdent . '/';

			if ($_I_MetodRead == 0) {
				$data = array
					(
						"Login" => $this->_S_UserLogin, 			//"Warlock" логин
						"SecurityWord" => $this->_S_UserPassword 	//"1" пароль
					);
			} else {				$data = array
					(
						"Идентификатор" => $this->_P_ID
					);
			}
			$JSONData = json_encode($data, JSON_UNESCAPED_UNICODE);
			$HTTPRequest = "GET";
			$HTTPHeader = array('Content-Type: application/json',
							'Content-Language: ru-RU');

			$Result = $MainConnect->execHTTPMetod($All_Message, $HTTPHeader, $HTTPRequest, $JSONData);

			If ($Result !== NULL) {

				if ($Result['Ошибка'] == True) {
					$_ReturnValue = False;
					$All_Message->Add_Message("Объект 'Пользователь'", $Result['ОписаниеОшибки'], 0, "Разработчик");
					$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка работы сайта. Выполните вход позже", 0, "Пользователь");
				} else {
					$ArrResult = $Result['Результат'];
					if (is_array($ArrResult)) {

						Foreach($ArrResult As $Value) {
							$Argument = $Value['Наименование'];
							$ValueArg = $Value['Значение'];

							$this->setValueClassVar($Argument, $ValueArg);
						}
						if ($this->_N_TypeUser == 1)
							$this->setPeopleName($ArrResult['Имя']['Значение'], $ArrResult['Отчество']['Значение'], $ArrResult['Фамилия']['Значение'], $ArrResult['Пол']['Значение']);
						unset($Argument, $ValueArg);
					}
					unset($ArrResult);
				}
			}
			$MainConnect->Str_HTTPWSAdress = "";
			unset($Result, $JSONData, $data, $HTTPAdress, $HTTPRequest, $HTTPHeader);

			return $_ReturnValue;
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

			//$this->_B_SubscribeNews 	= (bool)$Row[3];

			switch ($Argument) {
				case "Код":
					$this->_S_UserId = $Value;
					break;
				case "Логин":
					$this->_S_UserLogin = $Value;
					break;
				case "Ник пользователя":
					$this->S_User_Nik = $Value;
					break;
				case "Активен":
					$this->_B_UserActive = $Value;
					break;
				case "Доступ заблокирован":
					$this->_B_UserBlock = $Value;
					break;
				case "Код блокировки":
					$this->_S_MotiveBlockID = $Value;
					break;
				case "Причина блокировки":
					$this->_S_MotiveBlock = $Value;
					break;
				case "Идентификатор":
					$this->_P_ID = $Value;
					break;
				case "Код контрагента":
					$this->setPeopleID($Value);
					break;
				case "ЮрФизЛицо":
					$this->_N_TypeUser = $Value;
					break;
				case "Форма юридического образования":
					$this->_N_VidUser = $Value;
					break;
				case "Короткое наименование":
					$this->S_ShortName = $Value;
					break;
				case "Полное наименование":
					$this->S_FullName = $Value;
					break;
				case "ИНН":
					//$this->S_FullName = $Value;
					break;
				case "КПП":
					//$this->S_FullName = $Value;
					break;
				case "Пол":
					//$this->_B_SexMen = $Value;
					break;
				case "Дата рождения":
					//$this->S_FullName = $Value;
					break;
				case "Уровень доступа":
					if (is_array($Value)) {
						$Num_Row = 0;
						foreach ($Value as $TypeValue) {
							$this->_Array_UserCategory[$Num_Row] = $TypeValue;
							$Num_Row ++;
						}
						unset($Num_Row);
					}
					break;
				case "МассивЭлектронныхАдресов":
					if (is_array($Value)) {
						$this->_Array_EMail = array();
						$Num_Row = 0;
						foreach ($Value as $TypeValue) {
							$this->_Array_EMail[$Num_Row] = $TypeValue;
							$Num_Row ++;
						}
						unset($Num_Row);
					}
					break;
				case "Использовать куки":
					$this->_B_UseCoockies = $Value;
					break;
				case "Согласие с политикой":
					$this->_B_UserAgreePolicyData = $Value;
					break;
				case "Согласие с конфиденциальностью":
					$this->_B_UserAgreeConfData = $Value;
					break;
				case "Получать рассылку":
					$this->_B_SubscribeNews = $Value;
					break;
			}
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setUsePassword(String Login)
	### 	- установить свойство использовать пароль
		private function setUsePassword($_B_UsePassword) {
	###------- Входные параметры
	### _B_UsePassword		:Bool 		- значение сойства
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$this->_B_UsePassword	 = $_B_UsePassword;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setUserID(String ID)
	### 	- установить свойство ID пользователя
		private function setUserID($_SUserId) {
	###------- Входные параметры
	### _SUserId		:String		- значение ID пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$this->_S_UserId = $_SUserId;
			return true;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setUserLogin(String Login)
	### 	- установить свойство логин пользователя
		private function setUserLogin($Value) {
	###------- Входные параметры
	### _SUserLogin		:String 		- значение логина пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = False;
			/*
			echo $Value . "<br />";
			if (preg_match("/^[A-ZА-ЯЁёa-zа-я0-9]([A-ZА-ЯЁёa-zа-я0-9_-~=!\?.,@№#$%&*()]*)$/u", $Value))
				echo "Ровно <br />";
			else
				echo "Фигня <br />";
            */
			if (strlen($Value) > 0 && preg_match("/^[A-ZА-ЯЁёa-zа-я0-9]([A-ZА-ЯЁёa-zа-я0-9_-~=!\?.,@№#$%&*()]*)$/u", $Value)) {
				$this->_S_UserLogin	 = $Value;
				$_ReturnValue = True;
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setUserPassword(String Password)
	### 	- установить свойство пароль пользователя
		private function setUserPassword($Value) {
	###------- Входные параметры
	### _SUserPassword		:String			- HASH пароль пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = False;
			if (strlen($Value) > 0 && preg_match("/^([A-Za-zА-ЯЁёа-я0-9\?!.,~+-=_@№#$%&*()]*)$/u", $Value)) {				$this->_S_UserPassword = $Value;
				//$this->_S_UserPassword = $this->GenerateHash($Value);
				$_ReturnValue = True;
			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### setUserEMail(String Login, Adress Propperty)
	### 	- установить свойство логин пользователя
		private function setUserEMail($Value, &$Propperty) {
	###------- Входные параметры
	### Value		:String 		- значение почтового адресса
	### Propperty	:String 		- свойство для установки
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = False;
//			if (strlen($_SValue) > 0 && preg_match("/^(A-ZА-ЯЁёa-zа-я0-9)([A-ZА-ЯЁёa-zа-я0-9._+-\]+)@(A-ZА-ЯЁёa-zа-я0-9)([A-ZА-ЯЁёa-zа-я0-9._-]+).(A-ZА-ЯЁёa-zа-я){2,4}$/u", $_SUserLogin)) {
				$Propperty	 = $Value;
				$_ReturnValue = True;
//			}
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### getUserLogin()
	### 	- вернуть значение свойства Логин пользователя
		private function getUserLogin() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  String 	- значение свойства Логин
	###
			return $this->_S_UserLogin;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	ControlData(Object ErrorOfModul, Array Data)
	###		- контроль данных сессии на возможные ошибки
		Private Function ControlData($All_Message, $Arr_Sess) {
	###------- Входные параметры
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Array Data					- массив данных сессии пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$_ReturnValue = True;
			if (strlen($Arr_Sess["S_OldIPUser"]) <> 0 && ($Arr_Sess["S_OldIPUser"] !== $Arr_Sess["S_ThisIPUser"])) {
				$_ReturnValue = False;
				$All_Message->Add_Message("Объект 'Пользователь'", "Выполнен вход с адреса отличного от адреса посленего посещения. Необходимо выполнить вход повторно", 0, "Пользователь");
			}

			if (strlen($Arr_Sess["S_OldClient"]) <> 0 && ($Arr_Sess["S_OldClient"] !== $Arr_Sess["S_Client"])) {
				$_ReturnValue = False;
				$All_Message->Add_Message("Объект 'Пользователь'", "Выполнен вход из браузера отличного от браузера посленего посещения. Необходимо выполнить вход повторно", 0, "Пользователь");
			}

			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	###	UpdateData(Array Data)
	###		- обновить данные объекта согласно данных сессии пользователя
		Private Function UpdateData($Arr_Sess) {
	###------- Входные параметры
	###  Array Data					- массив данных сессии пользователя
	###------- Выходные параметры
	###  Bool 	- признак удачного выполнения функции
	###
			$this->_B_UsePassword = $Arr_Sess["B_UsePassword"];
			$this->_B_UseCookies = $Arr_Sess["B_UseCookies"];
			$this->_D_DateIn = date("Y-m-d");
			$this->_S_Client = $Arr_Sess["S_Client"];
			$this->_S_IPFrom = $Arr_Sess["S_ThisIPUser"];
			$this->_S_Refferer = $Arr_Sess["S_Refferer"];
			$this->_S_Forwarded = $Arr_Sess["S_Forwarded"];

			$Arr_Sess["S_IDUser"] = $this->getUserID();
			$Arr_Sess["B_UsePassword"] = False;

			return true;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###@@@@@@@@@@@@@@@@@@@@@
	### Генерируем хэш пароля
	### GenerateHash(String _Value_Var)
	### 	Генерирую Хэш-код для пароля
		Private Function GenerateHash($_Value_Var) {
	###------- Входные параметры
	###  String _Value_Var			- Значение переменной
	###------- Выходные параметры
	###  String закодированный пароль
	###
			$_ReturnValue = hash("md5", $_Value_Var, False);
			return $_ReturnValue;
		}
	###@@@@@@@@@@@@@@@@@@@@@

	###////// Внутренние текущего проекта

	###@@@@@@@@@@@@@@@@@@@@@
	### ReadBanersListFromBase(Object Connection, Object ErrorOfModul, Object DataSession)
	### 	- прочитать объекты пользователя из БД
		Private Function ReadBanersListFromBase(&$MainConnect, &$SystemValue, $All_Message, $Arr_Params) {
	###------- Входные параметры
	###  Connections Connections			- Объект содержащий сведения о подключении
	###  SystemConfig SystemValue			- Объект конфигурации приложения
	###  ErrorOfModul ErrorOfModul			- Объект хранения сообщений по системе
	###------- Выходные параметры
	###  bool 	- признак удачной операции
	###

			$_ReturnValue = True;

			If ($MainConnect->Boo_Use1CManager == True) {

				$All_Message->Add_Message("Объект 'Пользователь'", "Начало получения данных о банерах", 0, "Разработчик");

				$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/ws/PortalMaintenance.1cws?wsdl';

				$_ReturnValue = $MainConnect->setConnection($All_Message);

				$Result = NULL;
				If ($_ReturnValue) {					Try {
						$Arr_Params["Идентификатор"] = $this->_P_ID;  					// Идентификатор пользователя, что бы отобрать только порталы этого пользователя
						$JSONData = json_encode($Arr_Params, JSON_UNESCAPED_UNICODE);
						$_paramMethod = array(
								"CodePortal" => Str_PortalIdent,
								"Parameters" => $JSONData
							);
						$HTTPConnection = $MainConnect->ConnectDB;
						$Result = $HTTPConnection->GetBanersInfo($_paramMethod)->return;
					} Catch(Exception $e) {						$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка обращения к методу 'GetBanersInfo()' WEB сервиса '" . $MainConnect->Str_HTTPWSAdress . "'. " . $e->getMessage(), 0, "Разработчик", $e->getCode());
						$MainConnect->insertLogMessage($All_Message ,$e->getMessage());
						$_ReturnValue = False;
						$Result = NULL;
					}
				}
				$MainConnect->Str_HTTPWSAdress = "";

				If ($Result !== NULL && is_object($Result)) {
					If (isset($Result->Error) && $Result->Error == False) {
						$ArrResult = json_decode($Result->Result, True)['#value'];
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
										$_ArrayTemp['Object'] = $SystemValue->FindTypeBanerBySID($ValueTemp['SID']);
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
								$this->_Arr_Baners[$Num_Row] = $Obj_Baner;

								$Num_Row ++;
								unset($_Num_Temp, $Obj_Baner, $_Arr_Types, $_Arr_HTTP);
							}
							unset($Num_Row);
						} Else {							$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка получения данных о банерах. Некорректные данные ответа", 0, "Разработчик");
						}
						unset($ArrResult);
					} Else {
						$All_Message->Log_GlobalError = True;
						if (isset($Result->ErrorMessage))
							$All_Message->Add_Message("Объект 'Пользователь'", $Result->ErrorMessage, 0, "Разработчик");
						$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка получения данных о банерах. Ошибка неизвестна", 0, "Разработчик");
					}
				} Else {					$All_Message->Add_Message("Объект 'Пользователь'", "Ошибка получения данных о банерах. Неизвестный ответ сервиса '" . $MainConnect->Str_HTTPWSAdress . "'", 0, "Разработчик");
				}

				$All_Message->Add_Message("Объект 'Пользователь'", "Завершение получения данных о банерах", 0, "Разработчик");
				unset($Result, $HTTPAdress, $HTTPHeader, $HTTPRequest, $_paramMethod, $JSONData, $data);

			} Else {				$SQL_Query = "SELECT `ID` FROM `banerstable` WHERE `IDUser` = '" . $this->_S_UserId . "'";

	 			if ($Result = $MainConnect->execSQLQuery($All_Message, $SystemValue, $SQL_Query)) {
	 				$Num_Row = 0;
					While ($Row = $Result->fetch_row()) {
						$Obj_Baner = new BanerProperties(trim((string)$Row[0]));
						$Obj_Baner->ReadBanerBySID($MainConnect, $SystemValue, $All_Message);
						$this->_Arr_Baners[$Num_Row] = $Obj_Baner;
						$Num_Row ++;
						unset($Obj_Baner);
					}
				}
				else {
					$All_Message->Add_Message("Объект 'Пользователь'", "Не удалось прочитать данные пользователя", 0, "Пользователь");
					$_ReturnValue = False;
				}

				if (isset($Result))
					unset($Result);
				if (isset($Num_Row))
					unset($Num_Row);

				unset($SQL_Query);
			}

			return $_ReturnValue;
		}

	###@@@@@@@@@@@@@@@@@@@@@
	### updateDataUser1CMethod(Object Connection, Object ErrorOfModul, Object SystemConfig, Array Arr_Data)
	###		- выполнить изменение данных пользователя сервисными службами методом 1С
		Private Function updateDataUser1CMethod($MainConnect, $All_Message, $SystemValue, $Arr_Data) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Object SystemConfig		- данные сессии пользователя
	###  Array Arr_Data				- массив параметров для отправки подтверждения на адрес электронной почты
	###------- Выходные параметры
	###  Bool 	- признак удачной операции по отправке подтверждения на адрес электронной почты
	###

			$_ReturnValue = False;

			$MainConnect->Str_HTTPWSAdress = Str_HostName . '/' . Str_DBName . '/hs/UsersMaintenanceService/UserService/' . Str_PortalIdent . '/' . $this->_P_ID . '/';

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
	### updateDataUserPHPMethod(Object Connection, Object ErrorOfModul, Object SystemConfig, Array Arr_Data)
	###		- выполнить изменение данных пользователя сервисными службами
		Private Function updateDataUserPHPMethod($MainConnect, $All_Message, $SystemValue, $Arr_Data) {
	###------- Входные параметры
	###  Object Connections			- Объект содержащий сведения о подключении
	###  Object ErrorOfModul		- Объект хранения сообщений по системе
	###  Object SystemConfig		- данные сессии пользователя
	###  Array Arr_Data				- массив параметров для отправки подтверждения на адрес электронной почты
	###------- Выходные параметры
	###  Bool 	- признак удачной операции по отправке подтверждения на адрес электронной почты
	###

			$_ReturnValue = False;

			$All_Message->Add_Message("Приложение", "Функция отправки подтверждения на адрес электронной почты в разработке", 2, "Разработчик");

			return $_ReturnValue;

		}
	###@@@@@@@@@@@@@@@@@@@@@

	}

	////////////////////////////////////////////////////
	######      Конец описания объекта             #####
	####################################################

?>
