		left_over = ft_strdup(l_read);
		if (!left_over)
		{
			free(left_over);
			left_over = NULL;
		}
		/*if (l_read[(ft_strlen(l_read)) - 1] != '\n')
		{
			left_over = ft_strdup(l_read);
			if (!left_over)
			{
				free(left_over);
				left_over = NULL;
			}
			l_read = looking(fd);
			if (!l_read)
			{
				free(l_read);
				l_read = NULL;
				return (NULL);
			}
		}
		free(left_over);
		left_over = NULL;*/
		//printf("lo que devuelve join \n %s", l_read);
