<?php
	$_POST['statusPort'] = false;
	$_POST['macAddressArduino'] = "90-A2-DA-10-25-FL";
	$_POST['idRFID'] = "3333";

	$mysqli = new mysqli('localhost', 'root', 'root','samdoor');
	/* check connection */
	if ($mysqli->connect_errno) {
	    printf("Connect failed: %s\n", $mysqli->connect_error);
	    exit();
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

	/* Select queries return a resultset */
	if ($resulta = $mysqli->query("select Id_user from user where RFID = '".$id_RFID."'")) {
	    // Cycle through results
	    while ($row1 = $resulta->fetch_array()){
	        $GLOBALS['a'] = $row1['Id_user'];
	    }

	    /* free result set */
	    $resulta->close();
	}

	/* Select queries return a resultset */
	if ($resultb = $mysqli->query("select Id_room from room where Mac_address = '$mac_address_arduino'")) {
	    // Cycle through results
	    while ($row2 = $resultb->fetch_array()){
	        $GLOBALS['b'] = $row2['Id_room'];
	    }

	    /* free result set */
	    $resultb->close();
	}

	/* Create table doesn't return a resultset */
	if (mysqli_query($mysqli, "update room set State=".$id_RFID." where Mac_address = '$mac_address_arduino'") === TRUE) {
	    printf("gngn1.\n");
	}
		print_r($GLOBALS['a']);
		echo "<br>";
		print_r($GLOBALS['b']);
	/* Create table doesn't return a resultset */
	if (mysqli_query($mysqli, "insert into access (Id_user, Id_room, Result, Date) VALUES('".$GLOBALS['a']."','".$GLOBALS['b']."', 1,NOW())") === TRUE) {
	    printf("gngn2.\n");
	}
?>