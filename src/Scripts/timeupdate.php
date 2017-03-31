<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $date = date_create();
    echo("T::" . date("Y") . date("m") . date("d") . date("H") . date("i") . date("s"));
}
?>