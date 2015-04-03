/******************************************************/
//Function: strcopy
//Purpose: Copy source string to destination string
//Parameters: destination pointer and source pointer
/******************************************************/
void strcopy( char* destptr, char* sourceptr ){
	char* deststart = destptr;
	char* sourcestart = sourceptr;
	
	while( (*sourceptr) != '\0' ){
		(*destptr) = (*sourceptr);
		sourceptr++;
		destptr++;
	}

	(*destptr) = '\0';

	destptr = deststart;
	sourceptr = sourcestart;
}

/******************************************************/
//Function: strcomp
//Purpose: Compare 2 strings and return true if they are the same
//Parameters: 2 char pointers
/******************************************************/
bool strcomp( char* sptr1, char* sptr2 ){
	char* start1 = sptr1;
	char* start2 = sptr2;

	while( (*sptr1) != '\0' ){
		if( (*sptr1) == (*sptr2) ){
				sptr1++;
				sptr2++;
			}
		else{
			sptr1 = start1;
			sptr2 = start2;
			return false;
			break;
		}
	}
	if( (*sptr1)  == '\0' && (*sptr2) == '\0' ){
				sptr1 = start1;
				sptr2 = start2;
				return true;
	}
}

/******************************************************/
//Function: strlen
//Purpose: Find the length of a string (not including null character)
//Parameters: char pointer
/******************************************************/
int strlen( char* sptr ){
	int length = 0;
	while( (*sptr) != '\0' ){
		length++;
		sptr++;
	}
	return length;
}

/******************************************************/
//Function: strcat
//Purpose: Copy 2 source strings into a single destination string
//Parameters: destination pointer and 2 source pointers
/******************************************************/
void strcat( char* dest, char* first, char* second ){
	while( (*first) != '\0' ){
		(*dest) = (*first);
		dest++;
		first++;
	}
	while( (*second) != '\0' ){
		(*dest) = (*second);
		dest++;
		second++;
	}
	(*dest) = '\0';
}
