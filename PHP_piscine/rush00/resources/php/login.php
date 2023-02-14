<?php

include("auth.php");

include("sanitize.php");

sanitize($_POST["login"]);
sanitize($_POST["passwd"]);

session_start();
if (auth_admin($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["admin"] = TRUE;
	$_SESSION["login"] = $_POST["login"];
	header("location: adminpage.php");
}
else if (auth($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["login"] = $_POST["login"];
	header("location: ../../index.php");
}
else
{	
	$_SESSION["login"] = "";
	$_SESSION['message'] = "Log in failed!";
	header("location: login_page.php");
}
?>