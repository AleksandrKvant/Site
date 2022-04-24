<?php

$Str_ImgDir = "";
If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
	$Str_ImgDir = "./" . $SystemValue->getPictureDir();
Else
	$Str_ImgDir = "./" . Str_PictureDir . DS;
?>
<div class="MainUpRow">
	<div class="LogoSiteButton">
		<a href="index.php<?php echo getNewGetForAdresStroka()?>" title="Главная страница" target="_self" style="font-size: 24px">
			<img src="images/logoforsite.png" width="100%" hspace="0" height="100%" border="0" align="left" alt="" id="LogoScreen"/>
		</a>
	</div>
	<div class="NameSite_block">
		<a href="index.php<?php echo getNewGetForAdresStroka()?>" title="Главная страница" target="_self" style="text-decoration: none; color: #000 !important;">
			<div class="NameSite_text">Как заставить работать программы на бизнес или <strong>В</strong>се <strong>Э</strong>то <strong>П</strong>росто ...</div>
			<div class="NameSite_img">
				<img src="images/emogishok.gif" width="100%" hspace="0" height="100%" border="0" align="left" alt=""/>
			</div>
		</a>
	</div>
</div>
<div class="LeftPanel">
<?php
	//Построение меню для WEB страницы
	If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True) {

		If (count($SystemValue->getMenuPortal()) > 0) {

			$_Str_HTMLMenu = "<ul class=\"UlMainMenuSyte\">";

			ForEach ($SystemValue->getMenuPortal() as $Value) {

				If ((bool)$Value["ВыводитьВМеню"]) {
					$_Str_HTMLMenu = $_Str_HTMLMenu . "<li class=\"LiMainMenuSyte\"><a href=\"" . $Value["АдреснаяСтрока"] . getNewGetForAdresStroka() . "\">" . $Value["НаименованиеМеню"] . "</a></li>";
				}
				//print_r($Value);
				//echo "<br/>";
/*
<ul>
<li class="LiMainMenuSyte">
<a href="index.html">Главная</a>
</li>
			print_r($SystemValue->getMenuPortal());
*/
			}
			$_Str_HTMLMenu = $_Str_HTMLMenu . "</ul>";
			echo $_Str_HTMLMenu;
		}
	}

?>
	<div class="MetricsPanel">
<?php
	If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True) {
		If ((bool)$SystemValue->B_UseYandexMetriks) {
			echo $SystemValue->S_YandexMetriks;
		}
		If ((bool)$SystemValue->B_UseGoogleMetriks) {
			echo $SystemValue->S_GoogleMetriks;
		}
	}
?>
	</div>
</div>
<div class = "ContentConteiner">
