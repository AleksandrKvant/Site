<?php
###############################################################################
###	Модуль очистки переменных сеанса
### Разработан с целью обеспечения "Не забыть" при частых повторениях
###---------------------------------------------------------------------------
### Разработчик: А.Ю. Браун
### Дата разработки: 28.05.2015
###	Версия модуля: 1.00
###############################################################################

#============ отчистка переменных
if (isset($SystemValue))
	unset($SystemValue);
if (isset($Arr_Sess))
	unset($Arr_Sess);
if (isset($Str_Page))
	unset($Str_Page);
if (isset($All_Message))
	unset($All_Message);
if (isset($ActivUser))
	unset($ActivUser);
if (isset($MainConnect))
	unset($MainConnect);
if (isset($Mas_CountRecord))
	unset($Mas_CountRecord);
if (isset($B_ControlInputField))
	unset($B_ControlInputField);
if (isset($_Arr_Baners))
	unset($_Arr_Baners);
?>
