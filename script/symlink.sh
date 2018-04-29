#!/bin/bash
#Program:
#    Reproducing symbols linked to the local path
# History:
#    2018-3-31 wangtao V1.0.0

# find all the invalid symlink file and remove "./" before it
for sf in `find -L -type l | cut -d'/' -f2` ; do
   
    # parser and get symlink target file name
    file=`ls -l $sf | awk -F '/' '{ print $NF }'`
    
    # remove invalid symlink file and generate new one
    rm -f $sf && ln -s $file $sf
done
