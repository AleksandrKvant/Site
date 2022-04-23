</div>
<?php
/*
<div id = "main_RowDown">
	<table width = "100%" height = "100%" cellpadding = "0" cellspacing = "0">
		<tr width = "100%">
			<td width = "4px">
			</td>
			<td width = "400px" align = "left">
				<div class = "main_TextDown"><?php
	$_DefaultStr = "Сайт спроектирован и разработан: Александр Б.";
	$_StrTemp = "";
	If (isset($SystemValue)) {
		If (strlen($SystemValue->getDeveloper()) > 0)
			$_StrTemp = $SystemValue->getDeveloper();
		If (strlen($SystemValue->S_Designer) > 0)
			$_StrTemp = $_StrTemp . (strlen($_StrTemp) === 0 ? "" : ", ") . $SystemValue->S_Designer;
		If (strlen($_StrTemp) === 0)
			$_StrTemp = $_DefaultStr;
		If (strlen($SystemValue->getVersion() > 0))
			$_StrTemp = $_StrTemp . (strlen($_StrTemp) === 0 ? "" : ", ") . $SystemValue->getVersion();
		If (strlen($SystemValue->D_DateVersion > 0))
			$_StrTemp = $_StrTemp . ", "  . date("Y", strtotime($SystemValue->D_DateVersion)) . "г.";
		Else
			$_StrTemp = $_StrTemp . ", " . date("Y", mktime(0, 0, 0, 1, 5, 2021)) . "г.";
	}
	Else
		$_StrTemp = $_DefaultStr . ", " . date("Y", mktime(0, 0, 0, 1, 5, 2021)) . "г.";

	echo $_StrTemp;
	unset ($_DefaultStr, $_StrTemp);
?></div>
			</td>
			<td>
			</td>
<?php
	If (isset($Mas_CountRecord) && is_array($Mas_CountRecord)) {?>
			<td width = "250px" class = "main_TextDown" align = "right">
				<div class = "main_TextDown"><?php
		$Str_Stroka = strval($Mas_CountRecord[0]);
		While (strlen($Str_Stroka) < 6) {			$Str_Stroka = "0" . $Str_Stroka;		}
		echo "Д:" . $Str_Stroka;

		$Str_Stroka = strval($Mas_CountRecord[1]);
		While (strlen($Str_Stroka) < 7) {
			$Str_Stroka = "0" . $Str_Stroka;
		}
		echo "  М:" . $Str_Stroka;

		$Str_Stroka = strval($Mas_CountRecord[2]);
		While (strlen($Str_Stroka) < 8) {
			$Str_Stroka = "0" . $Str_Stroka;
		}
		echo "  Г:" . $Str_Stroka;
?></div>
			</td>
<?php
	}
?>
			<td width = "250px" align = "right">
				<div class = "main_TextDown" ><?php
	If (isset($SystemValue) && strlen($SystemValue->getAutor()) > 0)
		echo $SystemValue->getAutor();
	Else
		echo "Авторское право пренадлежит: Александр Б.()";
?></div>
			</td>
			<td width = "4px">
			</td>
		</tr>
	</table>
</div>
<?php
	If ($SystemValue->getUseCoockies() && ((isset($ActivUser) && is_object($ActivUser) && !$ActivUser->getUseCookies()) || (!$_SESSION['Log_CookiesOn']))) {?>
	<div class = "CookiesPanel">
		<H3>Сайт и Cookies</H3>
		<p>На этом сайте используются файлы cookie. Нажимая ПРИНЯТЬ вы разрешаете их использование. <a href="termsofuse.php" target="new" title="Прочитать Правила использования">Подробнее</a>
		<a style="font-size: 13pt; font-weight: 200; padding: 10px 25px 10px 25px" href = "#" id="But_CookiesOk">Принять</a></p>
	 </div>
<?php
	}
?>
*/
