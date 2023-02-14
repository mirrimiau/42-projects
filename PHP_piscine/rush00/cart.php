<?php
function validate(){
	$validate = "<div class=\"dropdown\">
  	<button onclick=\"finish()\" class=\"dropdown\"> Validate purchase </button>
	</div>";
	echo $validate;
}
function invalid(){
	$invalid = "<div class=\"dropdown\">
  	<button onclick=\"log()\" class=\"dropdown\"> Please log in to make purchases </button>
	</div>";
	echo $invalid;
}

function adddiv($title, $src, $qty) {

	$element = "<div>
	<a href=\"#\"><img src=\"$src\" alt=\"$title\" title=\"$title\"></a>
	<br><label>liters:</label>
	<input type=\"number\" id=\"quantity\" name=\"quantity\" min=\"1\" max=\"10\" value=\"$qty\">
	</div>";
	echo $element;
}

?>

<!DOCTYPE html>
<head>
    <title>Paint Market</title>
    <link rel="stylesheet" href="resources/css/index.css">
    <link rel="stylesheet" href="resources/css/cart.css">
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
        <form method="post" action="change_filter.php">
          <select id="filter" name="filter">
           <div class="dropdown">
             
             <option name="hue" value="brigth">Bright</option>
             <option name="hue" value="light">Light</option>
             <option name="hue" value="dark">Dark</option>
             
            </div>
          </select>
          <input type="submit" name="submit" value="Submit">
        </form>
      </div>
	<div class="list" ><h1 id="shoppingtitle">Shopping basket</h1></div><br/>
  <div class="flex-container">
	<?php
		$useritems = "resources/php/useritems";
		$items = unserialize(file_get_contents($useritems));
		foreach ($items as $value)
		{
			$title = $value['title'];
			$src = $value['src'];
			$qty = $value['qty'];
			adddiv($title, $src, intval($qty));
		}
	?>
  </div>
  <?php
    session_start();
    if($_SESSION["login"])
        validate();
    else
        invalid();
  ?>
  <script>
	  function finish() {
			alert("Thank you for shopping with us");
      window.location = "index.php";
			<?php 
        unlink("resources/php/useritems");
			?>
	  }
    function log() {
			window.location = "resources/php/login_page.php";
	  }
  </script>
</body>
</html>