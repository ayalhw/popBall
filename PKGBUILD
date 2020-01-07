# Maintainer: yt-theme <13133528465@163.com>
# Maintainerr: TransistorLogic <liuhongwu2003@outlook.com>

pkgname=yt-popball
pkgver=0.1
pkgrel=1
epoch=
pkgdesc="A PopBall"
arch=(x86_64)
url="https://github.com/yt-theme/popBall"
license=('GPLv3')
groups=()
depends=('qt5-base')
makedepends=('qt5-base')
checkdepends=()
optdepends=()
provides=("yt-popball")
conflicts=("yt-popball-git")
replaces=()
backup=()
options=()
install=
changelog=
source=("${pkgname}-${pkgver}.tar.gz")
noextract=()
md5sums=()
validpgpkeys=()

prepare() {
	cd "$pkgname-$pkgver"

}

build() {
	cd "$pkgname-$pkgver"
	#./configure --prefix=/usr
	qmake popBall.pro
	make

}

check() {
	cd "$pkgname-$pkgver"
	make -k check
}

package() {
	cd "$pkgname-$pkgver"
	install -D -m755 popBall "$pkgdir/usr/bin/$pkgname"
	
	install -D -m644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
	install -D -m644 res/$pkgname.desktop "$pkgdir/usr/share/applications/$pkgname.desktop"
	install -D -m644 README.md "$pkgdir/usr/share/doc/$pkgname/README.md"
	#install -D -m644 Changelog.md "$pkgdir/usr/share/doc/$pkgname/Changelog.md"
}
