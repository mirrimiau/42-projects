<?php

class Lannister
{
	function sleepWith($ifwilling)
	{
			if ($this->name === "Jaime" && get_class($ifwilling) == Cersei::class)
				print ("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
			else if (get_class($ifwilling) == Sansa::class)
				print ("Let's do this." . PHP_EOL);
			else
				print ("Not even if I'm drunk !" . PHP_EOL);
	}
}

?>