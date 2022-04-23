<?php

If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True) {
	If (count($SystemValue->getMenuPortal()) > 0) {
		ForEach ($SystemValue->getArrayPagesPortal() As $Value) {			//print_r($Value);
			If ($Str_Page === $Value["НаименованиеКраткое"]){				//echo $Value["ИмяФайлаПостОбработчика"];				include($SystemValue->getIncludeDir() . $Value["ИмяФайлаПостОбработчика"]);
				break;
			}
		}
	}
}
//Else
	//include(BASE_PATH . Str_IncludeDir . DS . $Value["ИмяФайлаОбработчика"]);
?>