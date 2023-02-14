<?php

class Targaryen 
{
	function resistsFire() {
		return false;
	}

	function getBurned()
	{
		if ($this->resistsFire())
			return ("emerges naked but unharmed");
		else
			return ("burns alive");
	}
}

?>