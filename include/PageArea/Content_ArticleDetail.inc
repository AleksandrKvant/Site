<?php
	###############################################################
	######       построение страницы "Статья"                ######
	###############################################################

	//Построение контента страницы
	$Ind = 0;
	$_Arr_AdressRaw = array();
	ForEach ($this->_Arr_Get as $Param => $Value) {
		If ($Param !== 'roleconnect') {
			$_Arr_AdressRaw[$Ind]['Параметр'] = $Param;
			$_Arr_AdressRaw[$Ind]['Значение'] = $Value;
			$Ind ++;
		}
	}
	unset($Ind);

	$Str_ImgDir = "";
	If ($SystemValue !== Null && is_object($SystemValue) && $SystemValue->getUseValueBD() == True)
		$Str_ImgDir = "./" . $SystemValue->getPictureDir();
	Else
		$Str_ImgDir = "./" . Str_PictureDir . DS;

	//print_r($this->_Arr_ContentType);
	//$this->getTextContentPageFromBase1CMethod($MainConnect, $All_Message, $SystemValue);

	//print_r($this->_Void_Data);
	If (count($this->_Void_Data) > 0 && isset($this->_Void_Data['ДетальныйКонтентСтраницы']) && is_array($this->_Void_Data['ДетальныйКонтентСтраницы'])) {
		$TempContent = $this->_Void_Data['ДетальныйКонтентСтраницы'];
		//!!!!
		//print_r($TempContent);
		//print_r($TempContent['Автор']);
		$Arr_Autor = json_decode($TempContent['Автор'], True)['#value'];
		$Arr_Rating = json_decode($TempContent['Рэйтинг'], True)['#value'];
		//print_r($Arr_Autor);
		$Str_ImgDirContent = $Str_ImgDir . "contents" . DS . "articles" . DS;
?>
	<table width="100%" cols="4" style="border-collapse: collapse;">
		<tbody>
			<tr class="TrContentElementArticleHeader">
				<td align="center" valign="middle" class="LogoElementArticle">
					<div class="ImgLogoListElementArticle">
<?php
		If (strlen(trim($TempContent['ИзображениеЛоготип'])) > 0) {
?>
						<img src="<?php echo $Str_ImgDirContent . $TempContent['ИзображениеЛоготип'] ?>"/>
<?php
		}
?>
					</div>
				</td>
				<td style="vertical-align: top;" colspan="3">
					<table cols="3" width=100%>
						<tbody>
							<tr width="100%" height="160px">
								<td colspan="4" align="center" valign="top">
									<div class="ContentElementArticleHeader"><?php echo $TempContent['Наименование'] ?></div>
								</td>
							</tr>
							<tr>
								<td class="ContentListElementArticleAutor">
									Опубликовал: <?php If (strlen(trim($Arr_Autor['Nickname'])) > 0) echo $Arr_Autor['Nickname']; Else echo $Arr_Autor['FIO'];?>
								</td>
								<td class="ContentListElementArticleAutor">
									<?php $date = new DateTime($TempContent['Дата']); echo $date->format('d.m.Y');?>
								</td>
								<td class="ContentListElementArticleAutor">
									<img src="<?php echo $Str_ImgDir ?>pictureviews.png" style = "margin: 0px 3px 0px 5px; width:30px; height:14px;"/> <?php echo $Arr_Rating['Views'] ?>
								</td>
								<td class="ContentListElementArticleAutor">
									<img src="<?php echo $Str_ImgDir ?>picturepositivefinger.png" style = "margin: 0px 3px 0px 5px; width:14px; height:14px;"/> <?php echo $Arr_Rating['GoodRating'] ?>
									<img src="<?php echo $Str_ImgDir ?>picturenegativefinger.png" style = "margin: 0px 3px 0px 5px; width:14px; height:14px;"/> <?php echo $Arr_Rating['BadRating'] ?>
								</td>
							</tr>
						</tbody>
					</table>
				</td>
			</tr>
			<tr>
				<td style="font-size: 18px" colspan="4">
					<div class="ContentElementArticleAbout">
						<strong><?php echo $TempContent['КраткоеОписание'] ?></strong>
					</div>
				</td>
			</tr>
			<tr>
				<td style="font-size: 18px" colspan="4">
					<div class="ContentElementArticleText">
						<?php echo $TempContent['Текст'] ?>
					</div>
				</td>
			</tr>
			<tr>
				<td class="ContentListElementArticleAutor">
					Автор: <?php If (strlen(trim($Arr_Autor['Nickname'])) > 0) echo $Arr_Autor['Nickname']; Else echo $Arr_Autor['FIO'];?>
				</td>
				<td class="ContentListElementArticleAutor">
					<?php $date = new DateTime($TempContent['Дата']); echo $date->format('d.m.Y');?>
				</td>
				<td class="ContentListElementArticleAutor">
					<img src="<?php echo $Str_ImgDir ?>pictureviews.png" style = "margin: 0px 3px 0px 5px; width:30px; height:14px;"/> <?php echo $Arr_Rating['Views'] ?>
				</td>
				<td class="ContentListElementArticleAutor">
					<img src="<?php echo $Str_ImgDir ?>picturepositivefinger.png" style = "margin: 0px 3px 0px 5px; width:14px; height:14px;"/> <?php echo $Arr_Rating['GoodRating'] ?>
					<img src="<?php echo $Str_ImgDir ?>picturenegativefinger.png" style = "margin: 0px 3px 0px 5px; width:14px; height:14px;"/> <?php echo $Arr_Rating['BadRating'] ?>
				</td>
			</tr>
<?php
		If ((bool)$TempContent['ЯвляетсяДубликатом']) {
?>
			<tr>
				<td colspan="3" align="right">
					Оригинал статьи опубликован по адресу: <?php echo $TempContent['АдресОригинала']?>
				</td>
			</tr>
<?php
		}
?>
		</tbody>
	</table>
	<div style="height: 25px;"></div>
<?php

	} Else {
?>
	<div class="ContentArticleHeader">Уважаемые посетители, скоро в этом разделе будет размещена соответствующая информация. Заходите на сайт и отслеживайте информацию.</div>
<?php
	}
/*
		ForEach ($this->_Arr_ContentType as $ValueContent) {
			$ContentFound = False;
			//print_r($ValueContent);
			ForEach ($this->_Void_Data as $Value) {
				If ($Value['TypeContent'] ===  $ValueContent['ВидКонтента']) {
					If (!$ContentFound) {
						$ContentFound = True;
?>
	<div class="ContentArticleHeader"><a target="_self" title="Переход в раздел <?php echo $ValueContent['ВидКонтента'] ?>" href="<?php echo $ValueContent['СтраницаАдреснаяСтрока'] . getNewGetForAdresStroka() ?>" style="text-decoration: none; color: #2E125B !important;"><?php echo $ValueContent['ВидКонтента'] ?></a></div>
	<table width="100%" cols="2" style="border-collapse: collapse;">
		<tbody>
<?php
					}
				//print_r($Value);
				//echo "<br/>";
				$HTTPLink= "";
				If (strlen($ValueContent['СтраницаДетализацииАдреснаяСтрока']) > 0) {
					$_Arr_NewAdrRaw = array();
					$Ind = count($_Arr_NewAdrRaw);
					$_Arr_NewAdrRaw[$Ind]['Параметр'] = "selcont";
					$_Arr_NewAdrRaw[$Ind]['Значение'] = $Value['PID'];
					$HTTPLink = $ValueContent['СтраницаДетализацииАдреснаяСтрока'] . getNewGetForAdresStroka($_Arr_NewAdrRaw);
				}
				$Str_ImgDirContent = $Str_ImgDir . "contents" . DS;
				If ($ValueContent['ВидКонтента'] === "Статьи") {
					$Str_ImgDirContent = $Str_ImgDirContent . "articles" . DS;
				}
?>
			<tr class="ListElementArticle">
				<td align="center" valign="middle" class="LogoListElementArticle">
					<div class="ImgLogoListElementArticle">
<?php
				If (strlen($HTTPLink) > 0) {
?>
						<a target="new" title="<?php echo $Value['Name'] ?>" href="<?php echo $HTTPLink ?>"><img src="<?php echo $Str_ImgDirContent . $Value['PicturePath'] ?>"/></a>
<?php
				} else {
?>
						<img src="<?php echo $Str_ImgDirContent . $Value['PicturePath'] ?>"/>
<?php
				}
?>
					</div>

				</td>
				<td class="ContentListElementArticle">
					<table width="100%" height="100%" align="left" cellpadding="3px" cellspacing="2px" cols="5" class="">
						<tbody>
							<tr>
								<td style="font-size: 24px; margin: 5px;" colspan="4">
<?php
				If (strlen($HTTPLink) > 0) {
?>
								  <a target="new" href="<?php echo $HTTPLink ?>" class="ContentListElementArticleName"><?php echo $Value['Name'] ?></a>
<?php
				} else {
?>
								  <div class="ContentListElementArticleName"><?php echo $Value['Name'] ?></div>
<?php
				}
?>
								</td>
								<td class="ContentListElementArticleAutor">Опубликовал: <?php echo $Value['Manager']['Nickname'] ?></td>
							</tr>
							<tr>
								<td>
								</td>
								<td>
								</td>
								<td>
								</td>
								<td>
								</td>
							</tr>
							<tr>
								<td style="font-size: 20px" colspan="5">
									<div class="ContentListElementArticleAbout">
										<?php echo $Value['Description'] ?>
									</div>
							</td>
							</tr>
							<tr class="ContentListElementArticleFooter">
								<td>
									Дата: <?php $date = new DateTime($Value['DataAdd']); echo $date->format('d.m.Y'); ?>
								</td>
								<td>
								</td>
								<td>
								</td>
								<td>
								</td>
								<td>
									Просмотров: <?php echo $Value['RatingInfo']['Views'] ?>
								</td>
							</tr>
						</tbody>
					</table>
				</td>
			</tr>
			<tr>
				<td colspan="2">
					<div style="border-bottom: 1px solid transparent; border-image: linear-gradient(to right, #0B0E7F, white); -webkit-border-image: -webkit-linear-gradient(left, #0B0E7F, white); -o-border-image: -o-linear-gradient(left, #0B0E7F, white); border-image-slice: 1;"></div>
				</td>
			</tr>
<?php
				}
			}
			If ($ContentFound) {
?>
		</tbody>
	</table>
<?php
			}
		}
	}
*/
	unset($ContentFound, $HTTPLink, $date, $_Arr_DataPage, $Arr_StrData, $Value, $ValueAdr, $Str_Temp, $Obj_Temp, $Str_ImgDir);
?>
