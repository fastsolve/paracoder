function newcomm_test
%Illustrate use of group and communicator routines in MMPI;
comm =MPI_COMM_WORLD;
rnk =comm_rank(comm);
siz =comm_size(comm);

[group, info] =mpi_Comm_group( comm);
assert(info==0);

if rnk<siz/2
    rnks =(int32(0:int32(siz/2)-int32(1)))';
    b=length(rnks);
    [newgroup, info] =mpi_Group_incl(group, int32(b), rnks);
    assert(info==0);
else
    rnks =(int32(siz/2):siz-int32(1))';
    b=length(rnks);
    [newgroup, info] =mpi_Group_incl(group, int32(b), rnks);
    assert(info==0);
end

[newcomm, info] =mpi_Comm_create(comm, newgroup);
assert(info==0);
rbuf =rnk;
[rbuf, info] =allreduce(rbuf, int32(1), MPI_SUM, newcomm);
assert(info==0);
[newrnk, info] =mpi_Group_rank(newgroup);
assert(info==0);
m2c_printf('rnk= %d, newrnk= %d sum of rnk in newcomm= %d;\n', rnk, newrnk, rbuf);