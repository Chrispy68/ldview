DIRECTORIES = ../TCFoundation ../LDLoader ../TRE ../LDLib
QMAKE = $(QTDIR)/bin/qmake

all: Makefile
	for DIR in $(DIRECTORIES); do	\
		cd $$DIR; $(MAKE) -k; cd ../QT;	\
	done;
	make
	lrelease LDView.pro

debug: Makefile
	for DIR in $(DIRECTORIES); do	\
		cd $$DIR; $(MAKE) debug; cd ../QT;	\
	done;
	make

clean:
	for DIR in $(DIRECTORIES); do		\
		cd $$DIR; $(MAKE) clean; cd ../QT;	\
	done;
	make clean

depend:
	for DIR in $(DIRECTORIES); do		\
		cd $$DIR; $(MAKE) depend; cd ../QT;	\
	done;

dotDirs: .ui .moc .obj .test
	if [ "$?" != "" ]; then			\
		for DIR in $?; do			\
			if [ ! -d $$DIR ]; then	\
				mkdir $$DIR;		\
			fi;						\
		done;						\
	fi;

.ui:
.moc:
.obj:
.test:

Makefile: LDView.pro $(QTDIR)/mkspecs/default/qmake.conf
	$(QMAKE) -o Makefile LDView.pro
