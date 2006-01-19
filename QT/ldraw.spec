Summary: LDraw is an open standard for LEGO CAD programs
Name: ldraw
Group: Applications/Multimedia
Version: 2005.01
Release: 1
License: undefined
URL: http://www.ldraw.org
Packager: Peter Bartfai <pbartfai@stardust.hu>
BuildRoot: %{_builddir}/%{name}

%description
LDraw is an open standard for LEGO CAD programs that allow the user to create virtual LEGO models and scenes.

%prep
cd $RPM_SOURCE_DIR
if [ ! -d ldraw ] ; then mkdir ldraw ; fi
cd ldraw
wget -N http://www.ldraw.org/download/software/ldraw/ldraw027.zip
wget -N http://www.ldraw.org/library/updates/complete.zip

%build

%install
if [ ! -d $RPM_BUILD_ROOT/usr/local/share/ ] ; then
	mkdir -p $RPM_BUILD_ROOT/usr/local/share/
fi
cd $RPM_BUILD_ROOT/usr/local/share/
if [ -d ldraw ] ; then rm -rf ldraw ; fi
unzip -q $RPM_SOURCE_DIR/ldraw/ldraw027.zip
unzip -q -o $RPM_SOURCE_DIR/ldraw/complete.zip
cd ldraw
if [ -d p ] ; then mv p P ; fi
if [ -d parts ] ; then mv parts PARTS ; fi

%files
/usr/local/share/ldraw

%clean
rm -rf $RPM_BUILD_ROOT

