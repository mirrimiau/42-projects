<!DOCTYPE html>
<head>
    <title>Paint Market</title>
    <link rel="stylesheet" href="resources/css/index.css">
    <meta charset="UTF-8">
</head>
<body>
    <span style="float:left";><?php session_start(); if($_SESSION["login"]){echo ("Logged in: ".$_SESSION["login"]);}?></span>
    <h1>
        <span style='color: rgb(51, 222, 111)'>P</span><span>aint market</span><span style='color: rgb(176, 33, 33)'>.</span>
    </h1>
      <hr><br>
    <div class="dropdown">
      <a href="index.php"><button class="dropbtn">Home</button></a>
      </div>
    <div class="dropdown">
        <a href="resources/php/login_page.php"><button class="dropbtn">Log In</button></a>
        </div>
    <div class="dropdown">
        <a href="cart.php"><button class="dropbtn">Shopping cart</button></a>
        </div>
      </div>
      <div class="dropdown">
        <form method="post" action="resources/php/change_filter.php">
          <select id="filter" name="filter">
           
              <option name="hue" value="brigth">Bright</option>
              <option name="hue" value="light">Light</option>
              <option name="hue" value="dark">Dark</option>
  
          </select>
          <input type="submit" name="submit" value="Submit">
        </form>
      </div>
    <div class="flex-container">
      <?php
			include("install.php");
      ?>
    </div>
</body>
</html>