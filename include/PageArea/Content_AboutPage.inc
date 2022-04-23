<?php
	###############################################################
	######      построение страницы "О сайте"                ######
	###############################################################

	//Построение контента страницы
	$Str_ImgDir = "";
	If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
		$Str_ImgDir = "./" . $SystemValue->getPictureDir();
	Else
		$Str_ImgDir = "./" . Str_PictureDir . DS;

?>
	<div class="center_div">
<?php
// Вывод картинки и ссылки на помощь - в разработке
/*
		<p style="text-align: right; font-size: 10pt; line-height: 1; display: block">
			<a title="Помощь" href="" ><img src='<?php echo $Str_ImgDir ?>PageDesign/HelpIcon.png' width="35px" height="35px" hspace="0" align="right" border="0" alt="Помощь" /></a>
		</p>
*/
?>
		<h3 style = "text-align: center">О проекте</h3>
<?php
		echo "<div align=\"justify\" style=\"text-indent:25px; padding-bottom: 10px; font-size: 12pt; border: solid black; border-width: 2px 0px 2px 0px; width: -moz-available\">";
		echo $SystemValue->S_About;
		echo "</div>";

	If (strlen($SystemValue->S_EmailContact) > 0) {
		If ($SystemValue->B_UseConfData) {
?>
		<p style="text-align: right; padding-bottom: 1px; font-size: 9pt;">
			<a title="Прочитать документ Правила использования портала" target="_blank" href="termsofuse.php<?php echo getNewGetForAdresStroka()?>">Правила использования портала </a>
		</p>
		<p style="text-align: right; padding-bottom: 1px; font-size: 9pt;">
			<a title="Прочитать документ Политика конфиденциальности портала" target="_blank" href="policysecurity.php<?php echo getNewGetForAdresStroka()?>">Политика конфиденциальности портала </a>
		</p>
<?php
		}
?>
		<p style="text-align: center; padding-bottom: 10px; font-size: 12pt;">
			<label>Написать нам: <?php echo $SystemValue->S_EmailContact ?></label>
		</p>
<?php
	}

	$_StrTempVer = "Версия портала: '" . $SystemValue->S_Version . "'";
	$_StrTempEngine = "";
	If ($SystemValue->B_EngineShow && strlen($SystemValue->getEngineName()) > 0)
		$_StrTempEngine = "Построено на движке: '" . $SystemValue->getEngineName() . "'";
	If ($SystemValue->B_EngineShow && strlen($SystemValue->getEngineVersion()) > 0)
		$_StrTempEngine = $_StrTempEngine . (strlen($_StrTempEngine) === 0 ? "" : "; ") . "версия: '" . $SystemValue->getEngineVersion() . "'";

?>
		<div style="padding-bottom: 10px; font-size: 10pt; width: 100%; border: solid gray; border-width: 1px 0px 1px 0px">
			<div style="padding: 10px; text-align: left; float: left"><?php echo $_StrTempVer ?></div>
			<div style="padding: 10px; text-align: right"><?php echo $_StrTempEngine ?></div>
			<div style="padding: 10px; text-align: right">Авторское право принадлежит: <?php echo $SystemValue->S_Autor ?></div>
			<div style="padding: 10px; text-align: right">Дизайн выполнен: <?php echo $SystemValue->S_Designer ?></div>
			<div style="padding: 10px; text-align: right">Разработал ресурс: <?php echo $SystemValue->S_Developer ?></div>
		</div>
		<div style="padding-bottom: 10px; text-align: bottom">
			<p style="padding-bottom: 10px; font-size: 10pt; text-align: center">
				<label><?php echo Date("Y") ?>г.</label>
			</p>
		</div>
	</div>
<?php
	unset($Str_ImgDir);
?>
