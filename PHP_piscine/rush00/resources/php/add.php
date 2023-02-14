<?php
	header("location: ../../index.php");
	if ($_POST['submit'] == "Add to cart")
	{
		$useritems = "useritems";
		$items = unserialize(file_get_contents($useritems));
		$newitem['title'] = $_POST['title'];
		$newitem['src'] = $_POST['src'];
		$newitem['qty'] = $_POST['quantity'];
		$items[] = $newitem;
		file_put_contents($useritems, serialize($items));
	}

?>