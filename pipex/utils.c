char *path_parcing(char *command, char **envp)
{
	char **mypaths;
	char *onepath;
	char *path;
	int i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (mypaths[i])
	{
		onepath = ft_strjoin(mypaths[i], "/");
		path = ft_strjoin(onepath, command);
		free(onepath);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void ft_execve(char *ag, char **envp)
{
	char **command;
	char *path;

	command = ft_split(argv, ' ');
	path = path_parsing(command[0], envp);
	if (execve(path, command, envp) == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
}
