<?php
	session_start();
	if($_SESSION["admin"] != TRUE)
	{
	   header("location: login_page.php");
	   exit();
	}
?>

<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>admin</title>
	<style>
		.mid_bar {
			position: absolute;
			left: 5%;
			width: 45%;
			height: 100vw;
			top: 9.5vw;
		}

		.rcorners3 {
			border-radius: 10px;
			background: rgb(114, 159, 177);
			width: 100%;
			height: 100%;
			/* 		box-shadow: 10px 10px 10px rgb(152, 152, 57); */
		}

		h2 	{
			font-size: 2vw;
		}
	</style>

</head>


<body style="background:rgb(42,0,42)">
	<h1 style="color: antiquewhite; font-size: 5vw; padding-left: 3vw;"> User info (admin):</h1>

	<div class="mid_bar">

		<div class="rcorners3">



			<form method="post" action="create_admin.php">
				<a href="printusers.php"><h2>Show all users</h2></a>
			</form>
			<form method="post" action="create_admin.php">
				<a href="printadmin.php"><h2>Show all admins</h2></a>
			</form>
			<form method="post" action="create_user.php">
				<h2>Create user:</h2>
				Username: <input type="text" name="login" value="" />
				<br />
				Password: <input type="text" name="passwd" value="" />
				<input type="submit" name="submit" value="OK" />
			</form>
			<form method="post" action="delete_user.php">
				<h2>Delete user: </h2>
				Username: <input type="text" name="login" value="" />

				<input type="submit" name="submit" value="OK" />
			</form>
			<form method="post" action="promote_user.php">
				<h2>Promote user:</h2>
				Username: <input type="text" name="login" value="" />
				<input type="submit" name="submit" value="OK" />
			</form>
			<form method="post" action="demote_admin.php">
				<h2>Demote admin:</h2>
				Username: <input type="text" name="login" value="" />
				<input type="submit" name="submit" value="OK" />
			</form>
			</form>
		</div>
	</div>
</body>

</html>