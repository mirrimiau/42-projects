<?php

class NightsWatch implements IFighter
{
	static $fighters;

	public function fight()
	{
		for($i = 0; $this->fighters[$i]; $i++)
		{
			$this->fighters[$i]->fight();
		}
	}

	function recruit($recruited)
	{
		if (in_array("IFighter", class_implements(get_class($recruited))))
			$this->fighters[] = $recruited;
	}

}

?>