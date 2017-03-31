<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
	$link = mysqli_connect("127.0.0.1", "admin", "root", "samdoor");

	/* check connection */
	if (mysqli_connect_errno()) {
	    echo("connection: failed");
	    exit();
	}

	/* check if server is alive */
	if (mysqli_ping($link)) {
	    echo("connection: ok");
	} else {
	    echo("connection: failed");
	}

	/* close connection */
	mysqli_close($link);
	
}
?>