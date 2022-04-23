<div id = develop_Window> <br>
<?php
	// формирование данных для разработчика
    if (isset($Mas_CountRecord)) {
		if (is_bool($Mas_CountRecord) === true){
			echo "Ошибка подсчета подключений.<br>\n";
		}
		elseif (is_array($Mas_CountRecord) === true) {
			echo "Посещений за день: ".$Mas_CountRecord[0]."<br>\n";
			echo "Посещений за месяц: ".$Mas_CountRecord[1]."<br>\n";
			echo "Посещений за год: ".$Mas_CountRecord[2]."<br>\n";
			echo "Посещений всего: ".$Mas_CountRecord[3]."<br>\n";
	    }
	}
	echo "Сегодня: " . date("d.m.Y H:i:s") . ".<br>\n";
	if ($All_Message->Count_Array_Messages("Пользователь") > 0) {
		echo "Пользователь: <br>\n";
		foreach ($All_Message->Array_Messages as $Value) {
			if ($Value->Message_Class === "Пользователь") {
				$S_HTMLStroka = "Блок: '" . $Value->Message_BlockName . "'. " . date("d.m.Y H:i:s", $Value->Message_Time) .
					" код ошибки: '" . $Value->Message_Num . "' файл: '" . $Value->Message_File .
					"' строка: '" . $Value->Message_Line . "' сообщение: '" . $Value->Message_Text . "'";
				echo $S_HTMLStroka . ".<br>\n";
			}
		}
	}

	echo "Админ: <br>\n";
	foreach ($All_Message->Array_Messages as $Value) {
		if ($Value->Message_Class === "Администратор") {
			$S_HTMLStroka = "Блок: '" . $Value->Message_BlockName . "'. " . date("d.m.Y H:i:s", $Value->Message_Time) .
				" код ошибки: '" . $Value->Message_Num . "' файл: '" . $Value->Message_File .
				"' строка: '" . $Value->Message_Line . "' сообщение: '" . $Value->Message_Text . "'";
			echo $S_HTMLStroka . "<br>\n";
		}
	}

	echo "Разработчик: <br>\n";
	foreach ($All_Message->Array_Messages as $Value) {
		if ($Value->Message_Class === "Разработчик") {
			$S_HTMLStroka = "Блок: '" . $Value->Message_BlockName . "'. " . date("d.m.Y H:i:s", $Value->Message_Time) .
				" код ошибки: '" . $Value->Message_Num . "' файл: '" . $Value->Message_File .
				"' строка: '" . $Value->Message_Line . "' сообщение: '" . $Value->Message_Text . "'";
			echo $S_HTMLStroka . ".<br>\n";
		}
	}

?>
<br>MESSAGES:<br>
<?php print_r($All_Message) ?>
<br>POST:<br>
<?php print_r($_POST) ?>
<br>GET:<br>
<?php print_r($_GET) ?>
<br>SESSION:<br>
<?php print_r($_SESSION) ?>
<br>SERVER:<br>
<?php print_r($_SERVER) ?>
</div>