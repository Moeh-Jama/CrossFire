 for(int i=0; i<player_number; i++)
	{
		printf("Current Player: (%d,%d)\n",cases[i].place->row,cases[i].place->column);

		printf("Choose a move option:\n");
		printf("1.Up\n2.Down\n3.Right\n4.Left\n");
		int choice;
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:{
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				cases[i].place->player_Identifier=-1;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place = board[row_n][column_n].up;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			case 2:{
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				cases[i].place->player_Identifier=-1;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place = &board[row_n][column_n].down;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			case 3:{
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				cases[i].place->player_Identifier=-1;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place = &board[row_n][column_n].right;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			case 4:{
				int row_n, column_n;
				row_n = cases[i].place->row;
				column_n = cases[i].place->column;
				cases[i].place->player_Identifier=-1;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				cases[i].place = &board[row_n][column_n].left;
				cases[i].place->player_Identifier=i+20;
				printf("%s\n(%d, %d)\n",cases[i].name_one, cases[i].place->row, cases[i].place->column);
				break;
			}
			default:{
				printf("Error has occurred\n");
				exit(0);
			}
		}
	}