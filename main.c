#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>



void get_files_to_watch(const char** files)
{
	files[0] = "file1";
	files[1] = "file2";
}


int main(int argc, char* argv[])
{
	pid_t process_id = 0;

	//int number_of_files = argc-1;
	const char* files_to_watch[number_of_files];

	int i; // loop counter
/*
	printf("number of files : %d\n",number_of_files);

	for ( i = 0 ; i < number_of_files ; i++)
	{
		files_to_watch[i] = argv[i+1];
	}
*/
	get_files_to_watch(files_to_watch);

	for (i = 0 ; i < number_of_files ; i++)
	{
		printf("file %d : %s\n",i, files_to_watch[i]);
	}

/*
	process_id = fork();
	if ( process_id < 0 )
	{
		printf("fork failed !\n");
		exit(1);
	}

	struct stat file_stat;
	time_t last_mtime, now_mtime;
	time_t last_mtimes[number_of_files];


	for ( i = 0 ; i < number_of_files ; i++)
	{
		if ( stat(files_to_watch[i],&file_stat) < 0 )
			return 1;
		else
			last_mtimes[i] = file_stat.st_mtime;
	}

	for ( i = 0 ; i < number_of_files ; i++)
	{
		printf("Initial mtime for %s :   %ld\n", files_to_watch[i], last_mtimes[i]);
	}

	if ( process_id > 0 )
	{
		printf("process forked : %d \n", process_id);
		exit(0);
	}

	while(1)
	{
		for (i = 0 ; i < number_of_files ; i++)
		{
			stat(files_to_watch[i],&file_stat);
			now_mtime = file_stat.st_mtime;
			if ( last_mtimes[i] < now_mtime )
			{
				printf("\n\tChange DETECTED ( file %s )\n", files_to_watch[i]);
				printf("\t last_mtime : %ld and now_mtime : %ld\n",last_mtimes[i], now_mtime);
				last_mtimes[i] = now_mtime;
			}
		}

		sleep(3);
	}
*/
	return 0;
}
