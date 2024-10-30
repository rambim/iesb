#include <stdio.h>
#include "mpi.h"

int main( argc, argv )
int argc;
char **argv;
{
    int          rank;
    int          packsize, position;
    int          a;
    double       b;
    char         packbuf[100];

    MPI_Init( &argc, &argv );

    MPI_Comm_rank( MPI_COMM_WORLD, &rank );

    do {
	if (rank == 0) {
	    scanf( "%d %lf", &a, &b );
	    packsize = 0;
	    MPI_Pack( &a, 1, MPI_INT, packbuf, 100, &packsize, 
		      MPI_COMM_WORLD );
	    MPI_Pack( &b, 1, MPI_DOUBLE, packbuf, 100, &packsize, 
		      MPI_COMM_WORLD );
	}
	MPI_Bcast( &packsize, 1, MPI_INT, 0, MPI_COMM_WORLD );
	MPI_Bcast( packbuf, packsize, MPI_PACKED, 0, MPI_COMM_WORLD );
	if (rank != 0) {
	    position = 0;
	    MPI_Unpack( packbuf, packsize, &position, &a, 1, MPI_INT, 
			MPI_COMM_WORLD );
	    MPI_Unpack( packbuf, packsize, &position, &b, 1, MPI_DOUBLE,
			MPI_COMM_WORLD );
	}
	
	printf( "Process %d got %d and %lf\n", rank, a, b );
    } while (a >= 0);

    MPI_Finalize( );
    return 0;
}