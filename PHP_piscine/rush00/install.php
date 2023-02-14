<?php
	function adddiv($title, $price, $imgsrc, $filter) {
		echo "<div>
		<p><button>$price</button></p>
		<a href=\"#\"><img src=\"$imgsrc\" alt=\"$title\" title=\"$title\"></a>
		<br><label>liters:</label>
		<form action=\"resources/php/add.php\" method=\"post\">
			<input type=\"number\" id=\"quantity\" name=\"quantity\" min=\"1\" max=\"10\" value=\"1\">
			<input type=\"hidden\" name=\"title\" value=\"$title\">
			<input type=\"hidden\" name=\"src\" value=\"$imgsrc\">
			<input type=\"submit\" name=\"submit\" value=\"Add to cart\">
		</form>
		</div>";
	}
	session_start();
	$file = fopen("resources/products.csv", "r");
	while(! feof($file))
		$array[] = fgetcsv($file);
	fclose($file);

	for ($i = 0; $i < sizeof($array); $i++)
	{
		$title = $array[$i][0];
		$price = $array[$i][1];
		$imgsrc = $array[$i][2];
		$filter = $array[$i][3];
		if ($filter == $_SESSION["filter"])
			adddiv($title, $price, $imgsrc, $filter);
	}
?>