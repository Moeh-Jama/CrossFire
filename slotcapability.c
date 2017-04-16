switch (nextSlot[ongoing_contestant].type)
	{
		case HILL:
		
		if 		(player[ongoing_contestant].dexterity < 50)
		{
					player[ongoing_contestant].strength -= 10;// subtract 10 from players dexterity if it is less than or equal to 50
		if (player[ongoing_contestant].strength < 0)// if player dexterity is less  than 0 then set player strength to 0
						player[ongoing_contestant].strength = 0;				
		}
		else if (player[ongoing_contestant].dexterity >= 60) 
		{
					player[ongoing_contestant].strength += 10; // add 10 to players strength if player dexterity is greater than 60
		if (player[ongoing_contestant].strength > 100) // if player strength is greater than 100 set strength to 100
						player[ongoing_contestant].strength = 100;				
		}
		
		case CITY: // if player moved to a city
		
		if (player[ongoing_contestant].smartness > 60) 
		{
				player[ongoing_contestant].magicSkills += 10; // add 10 to players magic skills if players smartness is greater than 60
		if (player[ongoing_contestant].magicSkills > 100) // if player magic skills is greater than 100 set magic skills to 100
					player[ongoing_contestant].magicSkills = 100;
		}
		
		else if (player[ongoing_contestant].smartness <= 50)
		{
				player[ongoing_contestant].dexterity -= 10;// subtract 10 from players dexterity if players smartness is less than or equal to 50
				
		if (player[ongoing_contestant].dexterity < 0)// if player dexterity is less  than 0 set player dexterity to 0
					player[ongoing_contestant].dexterity = 0;
		}
			break;
		
		// There is no change if the ground is level
		
		default:
			break;
	}
}
