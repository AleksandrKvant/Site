<?php
	###############################################################
	######       построение страницы "Проекты"               ######
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
		$Str_ImgDirContent = $Str_ImgDir . "contents" . DS . "projects" . DS;
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
								</td>
							</tr>
						</tbody>
					</table>
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
				</td>
			</tr>
<?php
		If ((bool)$TempContent['ЯвляетсяДубликатом']) {
?>
			<tr>
				<td colspan="3" align="right">
					Оригинал проектной информации опубликован по адресу: <?php echo $TempContent['АдресОригинала']?>
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
	unset($ContentFound, $HTTPLink, $date, $_Arr_DataPage, $Arr_StrData, $Value, $ValueAdr, $Str_Temp, $Obj_Temp, $Str_ImgDir);
?>
