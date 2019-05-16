
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * @link https://github.com/phalcon/zephir/issues/520
 */
ZEPHIR_INIT_CLASS(Test_Properties_PropertyArray) {

	ZEPHIR_REGISTER_CLASS(Test\\Properties, PropertyArray, test, properties_propertyarray, test_properties_propertyarray_method_entry, 0);

	/**
	 * This is a public property with an initial empty-array value
	 */
	zend_declare_property_null(test_properties_propertyarray_ce, SL("someEmptyArray"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a public property with an initial array value
	 */
	zend_declare_property_null(test_properties_propertyarray_ce, SL("someArray"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * This is a protected property with an initial empty-array value
	 */
	zend_declare_property_null(test_properties_propertyarray_ce, SL("otherArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	test_properties_propertyarray_ce->create_object = zephir_init_properties_Test_Properties_PropertyArray;
	return SUCCESS;

}

PHP_METHOD(Test_Properties_PropertyArray, __construct) {

	zval _1;
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 1);
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_zval(this_ptr, SL("someArray"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Test_Properties_PropertyArray, setOtherArray) {

	zval *arr, arr_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr_sub);

	zephir_fetch_params(0, 1, 0, &arr);



	zephir_update_property_zval(this_ptr, SL("otherArray"), arr);

}

PHP_METHOD(Test_Properties_PropertyArray, getOtherArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "otherArray");

}

PHP_METHOD(Test_Properties_PropertyArray, testIssues1831) {

	zval info, headers, _0$$3, _2$$3, _3$$3, _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_6 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_0$$3, this_ptr, SL("otherArray"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_0$$3);
		ZEPHIR_CALL_FUNCTION(&info, "array_shift", &_1, 58, &_0$$3);
		ZEPHIR_UNREF(&_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "header");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "stripos", &_4, 59, &info, &_2$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3$$3)) {
			zephir_array_append(&headers, &info, PH_SEPARATE, "test/properties/propertyarray.zep", 46);
			continue;
		} else {
			zephir_read_property(&_5$$5, this_ptr, SL("otherArray"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_MAKE_REF(&_5$$5);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_6, 60, &_5$$5, &info);
			ZEPHIR_UNREF(&_5$$5);
			zephir_check_call_status();
			break;
		}
	}
	RETURN_CCTOR(&headers);

}

zend_object *zephir_init_properties_Test_Properties_PropertyArray(zend_class_entry *class_type TSRMLS_DC) {

		zval _3$$4;
	zval _0, _2, _5, _1$$3, _4$$4, _6$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("otherArray"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("otherArray"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("someArray"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 1);
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 2);
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 3);
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 4);
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("someArray"), &_3$$4);
		}
		zephir_read_property(&_5, this_ptr, SL("someEmptyArray"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$5);
			array_init(&_6$$5);
			zephir_update_property_zval(this_ptr, SL("someEmptyArray"), &_6$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

