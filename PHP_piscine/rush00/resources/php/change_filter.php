<?php

session_start();
$_SESSION["filter"] = $_POST["filter"];
header("location: ../../index.php");
?>