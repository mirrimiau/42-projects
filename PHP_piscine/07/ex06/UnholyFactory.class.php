<?php

class UnholyFactory
{
	public $factory = array();

	function absorb($fighter)
	{
		if (get_parent_class($fighter) == Fighter::class)
		{
			if (in_array($fighter->ftype, $this->factory))
			{
				print("(Factory already absorbed a fighter of type ".$fighter->ftype.")" . PHP_EOL);
			}
			else
			{
				$this->factory[] = $fighter->ftype;
				print("(Factory absorbed a fighter of type ".$fighter->ftype.")" . PHP_EOL);
			}
		}
		else
		{
			print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
		}
	}

	function fabricate($fighter)
	{
		if (in_array($fighter, $this->factory))
		{
			print ("(Factory fabricates a fighter of type ".$fighter.")" . PHP_EOL);
			$newclass = ucfirst(str_replace(' ', '', $fighter));
			return (new $newclass);
		}
		else
		{
			print ("(Factory hasn't absorbed any fighter of type ".$fighter.")" . PHP_EOL);
		}
	}

}

?>