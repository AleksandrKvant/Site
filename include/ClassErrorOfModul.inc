<?php
	####################################################
	###   Объект Ошибки и сообщения системы       ######
	####################################################
 	Class ErrorOfModul {
 	### Наименование - ErrorOfModul
 	###  	Объект для хранения любых сообщений, возникающих в системе
    ###
    ###-------------------------------------------------
    ###  Требуются объекты для работы
    ### Object ErrMessage		// Класс "Сообщение"
	////////////////////////////////////////////////////
 	################    Свойства    ####################
	////////////////////////////////////////////////////
 	###////// Открытые
	### Log_GlobalError			:Bool			// Признак глобальной ошибки приложения - объявление переменной
	### Array_Messages			:Array			// Массив сообщений
	### Message_User			:String			// Временный сообщение
	###
 	###------------------------------------------------
 	###////// Защищенные
	###
 	###------------------------------------------------
 	###////// Внутренние
	###
 	###------------------------------------------------
	###////// Требующие реализации
	###
	////////////////////////////////////////////////////
	###########   Методы класса   ######################
	////////////////////////////////////////////////////
	###////// Открытые
	### __construct()		: Object 		- конструктор класса
	###
 	###------------------------------------------------
	###////// Внутренние
	###
 	###------------------------------------------------
	###////// Защищенные
	###
	////////////////////////////////////////////////////
	##########      Свойства класса        #############
	////////////////////////////////////////////////////
 	### Открытые свойства
 		public $Log_GlobalError;					// Признак глобальной ошибки приложения - объявление переменной
    	public $Array_Messages;						// Массив сообщений
		public $Message_User;						// Временный

	////////////////////////////////////////////////////
	##########        Методы класса        #############
	////////////////////////////////////////////////////

	###////// Открытые

    ###@@@@@@@@@@@@@@@@@@@@@
	### Конструктор класса
	### __construct()		: Object 		- конструктор класса
		function __construct() {
	###------- Входные параметры
	###
	###------- Выходные параметры
	###  Object 	- объект класса
	###
			$this->Log_GlobalError = false;
			$this->Message_User = "";
			$this->Array_Messages = array();
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
	### add_Message($Message_BlockName, $Message_Text, $Message_Category = 0, $Message_Class = 0, $Message_Num = 0, $Message_File = "", $Message_Line = "", $Message_FieldName = "")
	### 		- Добавление сообщения, которое необходимо хранить, в массив свойства
		function add_Message($S_BlockName, $S_Text, $I_Category = 0, $S_Class = "Пользователь", $I_Num = 0, $S_File = "", $I_Line = "", $S_FieldName = "") {
	###------- Входные параметры
	### S_BlockName
	### S_Text
	### I_Category
	### S_Class
	### I_Num
	### S_File
	### I_Line
	### S_FieldName
	###------- Выходные параметры
	###  Bool 	- признак удачного завершения функции
	###
 			$ReturnValue = False;
 			$Error_Object = new ErrMessage($S_BlockName, $S_Class, $I_Category, $S_Text, $I_Num, $S_File, $I_Line, $S_FieldName);
 			if (is_object($Error_Object)) {
	 			$this->Array_Messages[Count($this->Array_Messages)] = $Error_Object;
	 			$ReturnValue = True;
	 		}
	 		return $ReturnValue;
 		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
		// Подсчитывает количество сообщений
		function Count_Array_Messages($S_Class = "Пользователь") {
	###------- Входные параметры
	### String S_Category		- категория пользователя
	###------- Выходные параметры
	###  Integer  	- количество сообщений для категории
	###
			$Count_Mess = 0;
			if ($S_Class === "Разработчик") {
				$Count_Mess = Count($this->Array_Messages);
			}
			else {
				foreach ($this->Array_Messages AS $Value) {
					if ($Value->Message_Class === $S_Class) {
						$Count_Mess = $Count_Mess + 1;
					}
				}
			}
			return $Count_Mess;
		}
    ###@@@@@@@@@@@@@@@@@@@@@

    ###@@@@@@@@@@@@@@@@@@@@@
		// Найти сообщение для указанного имени поля
		function Find_Field_Message($S_BlockName, $S_FieldName, $S_Class) {
	###------- Входные параметры
	### String S_BlockName		- наименование блока
	### String S_FieldName		- наименование поля
	### String S_Class			- уровень пользователя
	###------- Выходные параметры
	###  Array  	- массив индексов сообщений в массиве или False, если не найдено
	###
	//		echo "Параметры: `" . $S_BlockNamee . "-" . $S_FieldName . "-" . $S_Class . "`";
	//		echo "<br>";
			$ReturnValue = False;
			$Arr_IndexMess = array();
			foreach ($this->Array_Messages AS $Key => $Value) {
				//$this->add_Message($Str_Page, "Ключ:'" . $Key . "'; Значение:'" . $Value . "'", 0, "Разработчик", 0, "", "", "");
	//			echo "Ключ: `" . $Key . "`; Значение: `" . $Value->Message_BlockName . "-" . $Value->Message_FieldName . "-" . $Value->Message_Class . "`";
	//			echo "<br>";
				if ($Value->Message_BlockName === $S_BlockName && $Value->Message_FieldName === $S_FieldName && $Value->Message_Class === $S_Class) {
					$Arr_IndexMess[count($Arr_IndexMess)] = $Key;
				}
			}
    //		print_r($Arr_IndexMess);
	//		echo "<br>";
			if (count($Arr_IndexMess) != 0)
				$ReturnValue = $Arr_IndexMess;

			return $ReturnValue;
		}
    ###@@@@@@@@@@@@@@@@@@@@@
 	}
	////////////////////////////////////////////////////
    ######      Конец описания объекта             #####
	####################################################
?>
