CC=/opt/xtools/arm920t/bin/arm-linux-gcc

all:
	$(CC) `ls *.c` -I/usr/local/bin/arm_mqttlib/lib/ /usr/local/bin/arm_mqttlib/lib/libmosquitto.so.1\
	      -I/usr/local/sqlite3/include /usr/local/sqlite3/lib/libsqlite3.so.0.8.6	-lpthread -L/usr/local/sqlite3/lib  -lsqlite3 -o port_mqtt
	sz port_mqtt
	make clean

clean:
	rm -f port_mqtt
