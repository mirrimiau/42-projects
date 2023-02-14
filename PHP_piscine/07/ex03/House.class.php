<?php

class House
{
	function getHouseName() {
		return ;
	}
	function getHouseMotto() {
		return ;
	}
	function getHouseSeat() {
		return ;
	}
	final function diagnose() {

	}
	function introduce()
	{
		print ("House ".$this->getHouseName()." of ".$this->getHouseSeat()." : \"".$this->getHouseMotto()."\"" . PHP_EOL);
	}

}