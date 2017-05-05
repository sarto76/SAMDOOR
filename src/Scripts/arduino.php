<?php
	$id_RFID = "6345199834";
	$status_port = false;
	$mac_address_arduino = "F9-07-75-B4-EE-00";
	$link = mysqli_connect('localhost', 'root', 'root','samdoor');
	if (!$link) {
	    die('Not connected : ' . mysqli_error());
	}		
	if(isset($_POST['statusPort'])){
		$status_port =  $_POST['statusPort'];
	}
	if(isset($_POST['macAddressArduino'])){
		$mac_address_arduino =  $_POST['macAddressArduino'];
	}
	if(isset($_POST['idRFID'])){
		$id_RFID =  $_POST['idRFID'];
	}
	$resultA = mysqli_query($link,"select Id_user from user where RFID = '$id_RFID'"); // seleziono l'id del user tramite l'id del rfid
	$resultN = mysqli_query($link,"select Id_room from room where Mac_address = '$mac_address_arduino'"); // seleziono l'id della camera tramite il mac address
	while ($row = mysqli_fetch_array($resultA, MYSQLI_NUM)) {
		echo 'ID User: ', $row[0], "\n";
		$idUser = $row[0];
	}
	while ($row = mysqli_fetch_array($resultN, MYSQLI_NUM)) {
		echo 'ID Room: ', $row[0], "\n";
		$idRoom = $row[0];
	}
	$resultB = mysqli_query($link,"update room set State='$status_port' where Mac_address = '$mac_address_arduino'"); // cambio lo stato 
	$resultC = mysqli_query($link,"insert into access VALUES($idUser,$idRoom, 0,now(),0,8001)"); // inserisco il valore nella tabella access

?>