# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Worm.Debug:
PostBuild.cocos2d.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.external.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_recast.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_tinyxml2.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxhash.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxtea.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_clipper.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_edtaa3func.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_convertUTF.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_poly2tri.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_md5.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
PostBuild.ext_unzip.Debug: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm:\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libcocos2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libexternal.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_recast.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_tinyxml2.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxhash.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxtea.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_clipper.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_edtaa3func.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_convertUTF.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_poly2tri.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_md5.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_unzip.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Debug/Worm.app/Contents/MacOS/Worm


PostBuild.cocos2d.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libcocos2d.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libcocos2d.a


PostBuild.ext_clipper.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_clipper.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_clipper.a


PostBuild.ext_convertUTF.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_convertUTF.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_convertUTF.a


PostBuild.ext_edtaa3func.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_edtaa3func.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_edtaa3func.a


PostBuild.ext_md5.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_md5.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_md5.a


PostBuild.ext_poly2tri.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_poly2tri.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_poly2tri.a


PostBuild.ext_recast.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_recast.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_recast.a


PostBuild.ext_tinyxml2.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_tinyxml2.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_tinyxml2.a


PostBuild.ext_unzip.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_unzip.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_unzip.a


PostBuild.ext_xxhash.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxhash.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxhash.a


PostBuild.ext_xxtea.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxtea.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxtea.a


PostBuild.external.Debug:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libexternal.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libexternal.a


PostBuild.Worm.Release:
PostBuild.cocos2d.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.external.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_recast.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_tinyxml2.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxhash.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxtea.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_clipper.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_edtaa3func.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_convertUTF.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_poly2tri.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_md5.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
PostBuild.ext_unzip.Release: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm:\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libcocos2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libexternal.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_recast.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_tinyxml2.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxhash.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxtea.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_clipper.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_edtaa3func.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_convertUTF.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_poly2tri.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_md5.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_unzip.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/Release/Worm.app/Contents/MacOS/Worm


PostBuild.cocos2d.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libcocos2d.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libcocos2d.a


PostBuild.ext_clipper.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_clipper.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_clipper.a


PostBuild.ext_convertUTF.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_convertUTF.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_convertUTF.a


PostBuild.ext_edtaa3func.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_edtaa3func.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_edtaa3func.a


PostBuild.ext_md5.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_md5.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_md5.a


PostBuild.ext_poly2tri.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_poly2tri.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_poly2tri.a


PostBuild.ext_recast.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_recast.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_recast.a


PostBuild.ext_tinyxml2.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_tinyxml2.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_tinyxml2.a


PostBuild.ext_unzip.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_unzip.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_unzip.a


PostBuild.ext_xxhash.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxhash.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxhash.a


PostBuild.ext_xxtea.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxtea.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxtea.a


PostBuild.external.Release:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libexternal.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libexternal.a


PostBuild.Worm.MinSizeRel:
PostBuild.cocos2d.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.external.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_recast.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_tinyxml2.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxhash.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxtea.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_clipper.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_edtaa3func.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_convertUTF.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_poly2tri.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_md5.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
PostBuild.ext_unzip.MinSizeRel: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm:\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libcocos2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libexternal.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_recast.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_tinyxml2.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxhash.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxtea.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_clipper.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_edtaa3func.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_convertUTF.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_poly2tri.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_md5.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_unzip.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/MinSizeRel/Worm.app/Contents/MacOS/Worm


PostBuild.cocos2d.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libcocos2d.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libcocos2d.a


PostBuild.ext_clipper.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_clipper.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_clipper.a


PostBuild.ext_convertUTF.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_convertUTF.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_convertUTF.a


PostBuild.ext_edtaa3func.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_edtaa3func.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_edtaa3func.a


PostBuild.ext_md5.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_md5.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_md5.a


PostBuild.ext_poly2tri.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_poly2tri.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_poly2tri.a


PostBuild.ext_recast.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_recast.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_recast.a


PostBuild.ext_tinyxml2.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_tinyxml2.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_tinyxml2.a


PostBuild.ext_unzip.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_unzip.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_unzip.a


PostBuild.ext_xxhash.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxhash.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxhash.a


PostBuild.ext_xxtea.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxtea.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxtea.a


PostBuild.external.MinSizeRel:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libexternal.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libexternal.a


PostBuild.Worm.RelWithDebInfo:
PostBuild.cocos2d.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.external.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_recast.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_tinyxml2.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxhash.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_xxtea.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_clipper.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_edtaa3func.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_convertUTF.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_poly2tri.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_md5.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
PostBuild.ext_unzip.RelWithDebInfo: /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm:\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libcocos2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libexternal.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_recast.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxhash.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxtea.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_clipper.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_convertUTF.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_poly2tri.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_md5.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_unzip.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/bin/Worm/RelWithDebInfo/Worm.app/Contents/MacOS/Worm


PostBuild.cocos2d.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libcocos2d.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libcocos2d.a


PostBuild.ext_clipper.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_clipper.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_clipper.a


PostBuild.ext_convertUTF.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_convertUTF.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_convertUTF.a


PostBuild.ext_edtaa3func.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a


PostBuild.ext_md5.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_md5.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_md5.a


PostBuild.ext_poly2tri.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_poly2tri.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_poly2tri.a


PostBuild.ext_recast.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_recast.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_recast.a


PostBuild.ext_tinyxml2.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a


PostBuild.ext_unzip.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_unzip.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_unzip.a


PostBuild.ext_xxhash.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxhash.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxhash.a


PostBuild.ext_xxtea.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxtea.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxtea.a


PostBuild.external.RelWithDebInfo:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libexternal.a:
	/bin/rm -f /Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libexternal.a




# For each target create a dummy ruleso the target does not have to exist
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/curl/prebuilt/mac/libcurl.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libcrypto.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/openssl/prebuilt/mac/libssl.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/png/prebuilt/mac/libpng.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/uv/prebuilt/mac/libuv_a.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/webp/prebuilt/mac/libwebp.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/cocos2d/external/zlib/prebuilt/mac/libz.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libcocos2d.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_clipper.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_convertUTF.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_edtaa3func.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_md5.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_poly2tri.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_recast.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_tinyxml2.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_unzip.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxhash.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libext_xxtea.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Debug/libexternal.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libcocos2d.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_clipper.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_convertUTF.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_edtaa3func.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_md5.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_poly2tri.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_recast.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_tinyxml2.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_unzip.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxhash.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libext_xxtea.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/MinSizeRel/libexternal.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libcocos2d.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_clipper.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_convertUTF.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_edtaa3func.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_md5.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_poly2tri.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_recast.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_tinyxml2.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_unzip.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxhash.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libext_xxtea.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/RelWithDebInfo/libexternal.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libcocos2d.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_clipper.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_convertUTF.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_edtaa3func.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_md5.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_poly2tri.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_recast.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_tinyxml2.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_unzip.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxhash.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libext_xxtea.a:
/Users/macbookpro/Downloads/Game2/Project/test/Worm/mac-build/lib/Release/libexternal.a:
/usr/lib/libiconv.dylib:
