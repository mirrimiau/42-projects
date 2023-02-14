<?php
	session_start();
	if ($_GET["error" == "nouser"])
		echo ("Log in failed!")
?>


<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>login</title>
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
			font-size: 4vw;
		}
	</style>

</head>

<body style="background:rgb(36, 42, 45)">
	<h1 style="color: antiquewhite; font-size: 5vw; padding-left: 5vw;"> LOG IN:</h1>

	<div class="mid_bar">

		<div class="rcorners3">
			<br>
			<?php if($_SESSION["login"]){echo ("Logged in: ".$_SESSION["login"]);}?>
			<form method="post" action="logout.php">
			<input type="submit" name="submit" value="Log out"/>
			</form>
			<form method="post" action="../../index.php">
			<input type="submit" name="submit" value="Back to page"/>
			</form>
			<form method="post" action="login.php">
				<h3>Log in:</h3>
				Username: <input type="text" name="login" value="" />
				<br />
				Password: <input type="password" name="passwd" value="" />
				<input type="submit" name="submit" value="OK" />
				<?php 
					if ($_SESSION['message'] !== "")
						echo($_SESSION['message']);
					$_SESSION['message'] = "";
				?>
			</form>
			<br>
			<form method="post" action="create_user.php">
				<h3>Register:</h3>
				Username: <input type="text" name="login" value="" />
				<br />
				Password: <input type="password" name="passwd" value="" />
				<input type="submit" name="submit" value="OK" />
				<?php 
					if ($_SESSION['message'] !== "")
						echo($_SESSION['message']);
					$_SESSION['message'] = "";
				?>
			</form>
			<br>
			<form method="post" action="modif_user.php">
				<h3>Change password:</h3>
				Username: <input type="text" name="login" value="" />
				<br />
				Old password: <input type="password" name="oldpw" value="" />
				<br />
				New password: <input type="password" name="newpw" value="" />
				<input type="submit" name="submit" value="OK" />
				
			</form>
			<br>
			<form method="post" action="delete_own_user.php">
				<h3>Delete my account:</h3>
				Username: <input type="text" name="login" value="" />
				<br />
				Are you sure? <input type="checkbox" name="tick" value="TRUE"/>
				<br />
				Password: <input type="password" name="passwd" value="" />
				<input type="submit" name="submit" value="OK" />
				
				
			</form>
		</div>
	</div>
</body>

</html>