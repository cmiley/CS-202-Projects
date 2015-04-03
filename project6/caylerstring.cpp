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
//Purpose: Compare 2 strings and return 0 if same, 1 if the first is alphabetically 
//				 after the second, -1 if the first is alphabetically before the second
//Parameters: 2 char pointers
/******************************************************/
int strcomp( char* s1, char* s2 ){
	while( (*s1) != '\0' ){
		if( (*s1) < (*s2) ){
			return -1;
		}
		else if ( (*s1) > (*s2) ){
			return 1;
		}
		else if ( (*s1) == (*s2) ){
			s1++;
			s2++;
		}
	}
	if( (*s1) == (*s2) && (*s1) == '\0' ){
		return 0;
	}
	else return 1;
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
