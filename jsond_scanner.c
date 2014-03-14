/* Generated by re2c 0.13.5 */
/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Jakub Zelenka <bukka@php.net>                                |
  +----------------------------------------------------------------------+
*/

#include "php.h"
#include "php_jsond_scanner.h"
#include "php_jsond_scanner_defs.h"
#include "jsond_parser.tab.h"

#define	YYCTYPE     char
#define	YYCURSOR    s->cursor
#define	YYLIMIT     s->limit
#define	YYMARKER    s->marker
#define	YYCTXMARKER s->ctxmarker

#define YYGETCONDITION()        s->state
#define YYSETCONDITION(yystate) s->state = yystate

#define	YYFILL(n)

#define PHP_JSON_TOKEN(token)  PHP_JSON_T_##token
#define	PHP_JSON_TOKEN_RETURN(token)  return PHP_JSON_TOKEN(token)
#define PHP_JSON_CONDITION_SET(condition) YYSETCONDITION(yyc##condition)
#define PHP_JSON_CONDITION_GOTO(condition) goto yyc_##condition

#define PHP_JSON_SCANNER_COPY_ESC() php_json_scanner_copy_string(s, 0)
#define PHP_JSON_SCANNER_COPY_UTF() php_json_scanner_copy_string(s, 5)
#define PHP_JSON_SCANNER_COPY_UTF_SP() php_json_scanner_copy_string(s, 11)


static void php_json_scanner_copy_string(php_json_scanner *s, int esc_size)
{
	size_t len = s->cursor - s->str_start - esc_size - 1;
	if (len) {
		memcpy(s->pstr, s->str_start, len);
		s->pstr += len;
	}
}

static int php_json_hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'F')
	{
		return c - ('A' - 10);
	}
	else if (c >= 'a' && c <= 'f')
	{
		return c - ('a' - 10);
	}
	else
	{
		/* this should never happened */
		return -1;
	}
}

static int php_json_ucs2_to_int_ex(php_json_scanner *s, int size, int start)
{
	int i, code = 0;
	char *pc = s->cursor - start;
	for (i = 0; i < size; i++) {
		code |= php_json_hex_to_int(*(pc--)) << (i * 4);
	}
	return code;
}

static int php_json_ucs2_to_int(php_json_scanner *s, int size)
{
	return php_json_ucs2_to_int_ex(s, size, 1);
}

void php_json_scanner_init(php_json_scanner *s, char *str, int str_len, long options)
{
	s->cursor = str;
	s->limit = str + str_len;
	s->options = options;
	PHP_JSON_CONDITION_SET(JS);
}

int php_json_scan(php_json_scanner *s)
{

std:
	s->token = s->cursor;


	{
		YYCTYPE yych;
		unsigned int yyaccept = 0;
		if (YYGETCONDITION() < 1) {
			goto yyc_JS;
		} else {
			if (YYGETCONDITION() < 2) {
				goto yyc_STR_P1;
			} else {
				goto yyc_STR_P2;
			}
		}
/* *********************************** */
yyc_JS:
		{
			static const unsigned char yybm[] = {
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0, 128,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				128,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				 64,  64,  64,  64,  64,  64,  64,  64, 
				 64,  64,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
			};

			yych = *YYCURSOR;
			if (yych <= '9') {
				if (yych <= ' ') {
					if (yych <= '\n') {
						if (yych <= 0x00) goto yy2;
						if (yych <= 0x08) goto yy4;
						if (yych <= '\t') goto yy6;
						goto yy8;
					} else {
						if (yych == '\r') goto yy9;
						if (yych <= 0x1F) goto yy4;
						goto yy6;
					}
				} else {
					if (yych <= ',') {
						if (yych == '"') goto yy10;
						if (yych <= '+') goto yy4;
						goto yy12;
					} else {
						if (yych <= '-') goto yy14;
						if (yych <= '/') goto yy4;
						if (yych <= '0') goto yy15;
						goto yy17;
					}
				}
			} else {
				if (yych <= 'm') {
					if (yych <= '\\') {
						if (yych <= ':') goto yy18;
						if (yych == '[') goto yy20;
						goto yy4;
					} else {
						if (yych <= ']') goto yy22;
						if (yych == 'f') goto yy24;
						goto yy4;
					}
				} else {
					if (yych <= 'z') {
						if (yych <= 'n') goto yy25;
						if (yych == 't') goto yy26;
						goto yy4;
					} else {
						if (yych <= '{') goto yy27;
						if (yych == '}') goto yy29;
						goto yy4;
					}
				}
			}
yy2:
			++YYCURSOR;
			{
		if (s->limit < s->cursor) {
			PHP_JSON_TOKEN_RETURN(EOI);
		} else {
			s->errcode = PHP_JSON_ERROR_SYNTAX;
			return PHP_JSON_T_ERROR;
		}
	}
yy4:
			++YYCURSOR;
yy5:
			{
		s->errcode = PHP_JSON_ERROR_SYNTAX;
		return PHP_JSON_T_ERROR;
	}
yy6:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy58;
yy7:
			{ goto std; }
yy8:
			yych = *++YYCURSOR;
			goto yy7;
yy9:
			yych = *++YYCURSOR;
			if (yych == '\n') goto yy56;
			goto yy5;
yy10:
			++YYCURSOR;
			{
		s->str_start = s->cursor;
		s->str_esc = 0;
		PHP_JSON_CONDITION_SET(STR_P1);
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy12:
			++YYCURSOR;
			{ return ','; }
yy14:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy5;
			if (yych <= '0') goto yy55;
			if (yych <= '9') goto yy45;
			goto yy5;
yy15:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy47;
			} else {
				if (yych <= 'E') goto yy48;
				if (yych == 'e') goto yy48;
			}
yy16:
			{
		zend_bool bigint = 0, negative = s->token[0] == '-';
		int digits = s->cursor - s->token - negative;
		int max_digits = MAX_LENGTH_OF_LONG - 1;
		if (digits >= max_digits) {
			if (digits == max_digits) {
				int cmp = strncmp(s->token + negative, long_min_digits, max_digits);
				if (!(cmp < 0 || (cmp == 0 && negative))) {
					bigint = 1;
				}
			} else {
				bigint = 1;
			}
		}
		if (!bigint) {
			ZVAL_LONG(&s->value, strtol(s->token, NULL, 10));
			PHP_JSON_TOKEN_RETURN(INT);
		} else if (s->options & PHP_JSON_BIGINT_AS_STRING) {
			ZVAL_STRINGL(&s->value, s->token, s->cursor - s->token, 1);
			PHP_JSON_TOKEN_RETURN(STRING);
		} else {
			ZVAL_DOUBLE(&s->value, zend_strtod(s->token, NULL));
			PHP_JSON_TOKEN_RETURN(DOUBLE);
		}
	}
yy17:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			goto yy46;
yy18:
			++YYCURSOR;
			{ return ':'; }
yy20:
			++YYCURSOR;
			{ return '['; }
yy22:
			++YYCURSOR;
			{ return ']'; }
yy24:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'a') goto yy40;
			goto yy5;
yy25:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'u') goto yy36;
			goto yy5;
yy26:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'r') goto yy31;
			goto yy5;
yy27:
			++YYCURSOR;
			{ return '{'; }
yy29:
			++YYCURSOR;
			{ return '}'; }
yy31:
			yych = *++YYCURSOR;
			if (yych == 'u') goto yy33;
yy32:
			YYCURSOR = YYMARKER;
			if (yyaccept <= 1) {
				if (yyaccept <= 0) {
					goto yy16;
				} else {
					goto yy5;
				}
			} else {
				goto yy52;
			}
yy33:
			yych = *++YYCURSOR;
			if (yych != 'e') goto yy32;
			++YYCURSOR;
			{
		ZVAL_TRUE(&s->value);
		return PHP_JSON_T_TRUE;
	}
yy36:
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy32;
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy32;
			++YYCURSOR;
			{
		ZVAL_NULL(&s->value);
		PHP_JSON_TOKEN_RETURN(NUL);
	}
yy40:
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy32;
			yych = *++YYCURSOR;
			if (yych != 's') goto yy32;
			yych = *++YYCURSOR;
			if (yych != 'e') goto yy32;
			++YYCURSOR;
			{
		ZVAL_FALSE(&s->value);
		return PHP_JSON_T_FALSE;
	}
yy45:
			yyaccept = 0;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
yy46:
			if (yybm[0+yych] & 64) {
				goto yy45;
			}
			if (yych <= 'D') {
				if (yych != '.') goto yy16;
			} else {
				if (yych <= 'E') goto yy48;
				if (yych == 'e') goto yy48;
				goto yy16;
			}
yy47:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy32;
			if (yych <= '9') goto yy53;
			goto yy32;
yy48:
			yych = *++YYCURSOR;
			if (yych <= ',') {
				if (yych != '+') goto yy32;
			} else {
				if (yych <= '-') goto yy49;
				if (yych <= '/') goto yy32;
				if (yych <= '9') goto yy50;
				goto yy32;
			}
yy49:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy32;
			if (yych >= ':') goto yy32;
yy50:
			++YYCURSOR;
			yych = *YYCURSOR;
			if (yych <= '/') goto yy52;
			if (yych <= '9') goto yy50;
yy52:
			{
		ZVAL_DOUBLE(&s->value, zend_strtod(s->token, NULL));
		PHP_JSON_TOKEN_RETURN(DOUBLE);
	}
yy53:
			yyaccept = 2;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
			if (yych <= 'D') {
				if (yych <= '/') goto yy52;
				if (yych <= '9') goto yy53;
				goto yy52;
			} else {
				if (yych <= 'E') goto yy48;
				if (yych == 'e') goto yy48;
				goto yy52;
			}
yy55:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy47;
				goto yy16;
			} else {
				if (yych <= 'E') goto yy48;
				if (yych == 'e') goto yy48;
				goto yy16;
			}
yy56:
			yych = *++YYCURSOR;
			goto yy7;
yy57:
			++YYCURSOR;
			yych = *YYCURSOR;
yy58:
			if (yybm[0+yych] & 128) {
				goto yy57;
			}
			goto yy7;
		}
/* *********************************** */
yyc_STR_P1:
		yych = *YYCURSOR;
		if (yych <= 0xDF) {
			if (yych <= '[') {
				if (yych <= 0x1F) goto yy61;
				if (yych == '"') goto yy65;
				goto yy63;
			} else {
				if (yych <= '\\') goto yy67;
				if (yych <= 0x7F) goto yy63;
				if (yych <= 0xC1) goto yy69;
				goto yy71;
			}
		} else {
			if (yych <= 0xEF) {
				if (yych <= 0xE0) goto yy72;
				if (yych <= 0xEC) goto yy73;
				if (yych <= 0xED) goto yy74;
				goto yy75;
			} else {
				if (yych <= 0xF0) goto yy76;
				if (yych <= 0xF3) goto yy77;
				if (yych <= 0xF4) goto yy78;
				goto yy69;
			}
		}
yy61:
		++YYCURSOR;
		{
		s->errcode = PHP_JSON_ERROR_CTRL_CHAR;
		return PHP_JSON_T_ERROR;
	}
yy63:
		++YYCURSOR;
yy64:
		{ PHP_JSON_CONDITION_GOTO(STR_P1); }
yy65:
		++YYCURSOR;
		{
		char *str;
		size_t len = s->cursor - s->str_start - s->str_esc - 1;
		if (len == 0) {
			PHP_JSON_CONDITION_SET(JS);
			ZVAL_EMPTY_STRING(&s->value);
			PHP_JSON_TOKEN_RETURN(ESTRING);
		}
		str = emalloc(len + 1);
		str[len] = 0;
		ZVAL_STRINGL(&s->value, str, len, 0);
		if (s->str_esc) {
			s->pstr = Z_STRVAL(s->value);
			s->cursor = s->str_start;
			PHP_JSON_CONDITION_SET(STR_P2);
			PHP_JSON_CONDITION_GOTO(STR_P2);
		} else {
			memcpy(Z_STRVAL(s->value), s->str_start, len);
			PHP_JSON_CONDITION_SET(JS);
			PHP_JSON_TOKEN_RETURN(STRING);
		}
	}
yy67:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 'e') {
			if (yych <= '/') {
				if (yych == '"') goto yy91;
				if (yych >= '/') goto yy91;
			} else {
				if (yych <= '\\') {
					if (yych >= '\\') goto yy91;
				} else {
					if (yych == 'b') goto yy91;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= 'f') goto yy91;
				if (yych == 'n') goto yy91;
			} else {
				if (yych <= 's') {
					if (yych <= 'r') goto yy91;
				} else {
					if (yych <= 't') goto yy91;
					if (yych <= 'u') goto yy93;
				}
			}
		}
yy68:
		{
		s->errcode = PHP_JSON_ERROR_SYNTAX;
		return PHP_JSON_T_ERROR;
	}
yy69:
		++YYCURSOR;
yy70:
		{
		s->errcode = PHP_JSON_ERROR_UTF8;
		return PHP_JSON_T_ERROR;
	}
yy71:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy70;
		if (yych <= 0xBF) goto yy82;
		goto yy70;
yy72:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x9F) goto yy70;
		if (yych <= 0xBF) goto yy90;
		goto yy70;
yy73:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy70;
		if (yych <= 0xBF) goto yy89;
		goto yy70;
yy74:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy70;
		if (yych <= 0x9F) goto yy88;
		goto yy70;
yy75:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy70;
		if (yych <= 0xBF) goto yy87;
		goto yy70;
yy76:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x8F) goto yy70;
		if (yych <= 0xBF) goto yy85;
		goto yy70;
yy77:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy70;
		if (yych <= 0xBF) goto yy83;
		goto yy70;
yy78:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy70;
		if (yych >= 0x90) goto yy70;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy81;
yy80:
		YYCURSOR = YYMARKER;
		if (yyaccept <= 1) {
			if (yyaccept <= 0) {
				goto yy68;
			} else {
				goto yy70;
			}
		} else {
			goto yy102;
		}
yy81:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych >= 0xC0) goto yy80;
yy82:
		yych = *++YYCURSOR;
		goto yy64;
yy83:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych >= 0xC0) goto yy80;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy82;
		goto yy80;
yy85:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych >= 0xC0) goto yy80;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy82;
		goto yy80;
yy87:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy82;
		goto yy80;
yy88:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy82;
		goto yy80;
yy89:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy82;
		goto yy80;
yy90:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy80;
		if (yych <= 0xBF) goto yy82;
		goto yy80;
yy91:
		++YYCURSOR;
		{
		s->str_esc++;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy93:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy80;
				if (yych >= '1') goto yy95;
			} else {
				if (yych <= '@') goto yy80;
				if (yych <= 'C') goto yy95;
				goto yy96;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy95;
				if (yych <= '`') goto yy80;
				goto yy95;
			} else {
				if (yych <= 'd') goto yy96;
				if (yych <= 'f') goto yy95;
				goto yy80;
			}
		}
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy80;
			if (yych <= '0') goto yy115;
			if (yych <= '7') goto yy116;
			goto yy97;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy80;
				goto yy97;
			} else {
				if (yych <= '`') goto yy80;
				if (yych <= 'f') goto yy97;
				goto yy80;
			}
		}
yy95:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych <= '9') goto yy97;
			goto yy80;
		} else {
			if (yych <= 'F') goto yy97;
			if (yych <= '`') goto yy80;
			if (yych <= 'f') goto yy97;
			goto yy80;
		}
yy96:
		yych = *++YYCURSOR;
		if (yych <= 'B') {
			if (yych <= '7') {
				if (yych <= '/') goto yy80;
			} else {
				if (yych <= '9') goto yy98;
				if (yych <= '@') goto yy80;
				goto yy98;
			}
		} else {
			if (yych <= '`') {
				if (yych <= 'F') goto yy99;
				goto yy80;
			} else {
				if (yych <= 'b') goto yy98;
				if (yych <= 'f') goto yy99;
				goto yy80;
			}
		}
yy97:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych <= '9') goto yy112;
			goto yy80;
		} else {
			if (yych <= 'F') goto yy112;
			if (yych <= '`') goto yy80;
			if (yych <= 'f') goto yy112;
			goto yy80;
		}
yy98:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych <= '9') goto yy103;
			goto yy80;
		} else {
			if (yych <= 'F') goto yy103;
			if (yych <= '`') goto yy80;
			if (yych <= 'f') goto yy103;
			goto yy80;
		}
yy99:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy100;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy100:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy101;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy101:
		++YYCURSOR;
yy102:
		{
		s->errcode = PHP_JSON_ERROR_UTF16;
		return PHP_JSON_T_ERROR;
	}
yy103:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy104;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy104:
		yyaccept = 2;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych != '\\') goto yy102;
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy80;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy107;
		if (yych != 'd') goto yy80;
yy107:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy80;
		if (yych <= 'F') goto yy108;
		if (yych <= 'b') goto yy80;
		if (yych >= 'g') goto yy80;
yy108:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy109;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy109:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy110;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy110:
		++YYCURSOR;
		{
		s->str_esc += 8;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy112:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy113;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy113:
		++YYCURSOR;
		{
		s->str_esc += 3;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy115:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych <= '7') goto yy120;
			if (yych <= '9') goto yy117;
			goto yy80;
		} else {
			if (yych <= 'F') goto yy117;
			if (yych <= '`') goto yy80;
			if (yych <= 'f') goto yy117;
			goto yy80;
		}
yy116:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy117;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy117:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy118;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy118:
		++YYCURSOR;
		{
		s->str_esc += 4;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy120:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy80;
			if (yych >= ':') goto yy80;
		} else {
			if (yych <= 'F') goto yy121;
			if (yych <= '`') goto yy80;
			if (yych >= 'g') goto yy80;
		}
yy121:
		++YYCURSOR;
		{
		s->str_esc += 5;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
/* *********************************** */
yyc_STR_P2:
		yych = *YYCURSOR;
		if (yych == '"') goto yy127;
		if (yych == '\\') goto yy129;
		++YYCURSOR;
		{ PHP_JSON_CONDITION_GOTO(STR_P2); }
yy127:
		++YYCURSOR;
		YYSETCONDITION(yycJS);
		{
		PHP_JSON_SCANNER_COPY_ESC();
		PHP_JSON_TOKEN_RETURN(STRING);
	}
yy129:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych == 'u') goto yy131;
yy130:
		{
		char esc;
		PHP_JSON_SCANNER_COPY_ESC();
		switch (*s->cursor) {
			case 'b':
				esc = '\b';
				break;
			case 'f':
				esc = '\f';
				break;
			case 'n':
				esc = '\n';
				break;
			case 'r':
				esc = '\r';
				break;
			case 't':
				esc = '\t';
				break;
			case '\\':
			case '/':
			case '"':
				esc = *s->cursor;
				break;
			default:
				s->errcode = PHP_JSON_ERROR_SYNTAX;
				return PHP_JSON_T_ERROR;
		}
		*(s->pstr++) = esc;
		++YYCURSOR;
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy131:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy132;
				if (yych <= '0') goto yy133;
				goto yy134;
			} else {
				if (yych <= '@') goto yy132;
				if (yych <= 'C') goto yy134;
				goto yy135;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy134;
				if (yych >= 'a') goto yy134;
			} else {
				if (yych <= 'd') goto yy135;
				if (yych <= 'f') goto yy134;
			}
		}
yy132:
		YYCURSOR = YYMARKER;
		goto yy130;
yy133:
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy132;
			if (yych <= '0') goto yy150;
			if (yych <= '7') goto yy151;
			goto yy137;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy132;
				goto yy137;
			} else {
				if (yych <= '`') goto yy132;
				if (yych <= 'f') goto yy137;
				goto yy132;
			}
		}
yy134:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych <= '9') goto yy137;
			goto yy132;
		} else {
			if (yych <= 'F') goto yy137;
			if (yych <= '`') goto yy132;
			if (yych <= 'f') goto yy137;
			goto yy132;
		}
yy135:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych <= '7') goto yy137;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'B') goto yy136;
			if (yych <= '`') goto yy132;
			if (yych >= 'c') goto yy132;
		}
yy136:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych <= '9') goto yy141;
			goto yy132;
		} else {
			if (yych <= 'F') goto yy141;
			if (yych <= '`') goto yy132;
			if (yych <= 'f') goto yy141;
			goto yy132;
		}
yy137:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy138;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy138:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy139;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy139:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 4);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) (0xe0 | (utf16 >> 12));
		*(s->pstr++) = (char) (0x80 | ((utf16 >> 6) & 0x3f));
		*(s->pstr++) = (char) (0x80 | (utf16 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy141:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy142;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy142:
		yych = *++YYCURSOR;
		if (yych != '\\') goto yy132;
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy132;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy145;
		if (yych != 'd') goto yy132;
yy145:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy132;
		if (yych <= 'F') goto yy146;
		if (yych <= 'b') goto yy132;
		if (yych >= 'g') goto yy132;
yy146:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy147;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy147:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy148;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy148:
		++YYCURSOR;
		{
		int utf32, utf16_hi, utf16_lo;
		utf16_hi = php_json_ucs2_to_int(s, 4);
		utf16_lo = php_json_ucs2_to_int_ex(s, 4, 7);
		utf32 = ((utf16_hi & 0x3FF) << 10) + (utf16_lo & 0x3FF) + 0x10000;
		PHP_JSON_SCANNER_COPY_UTF_SP();
		*(s->pstr++) = (char) (0xf0 | (utf32 >> 18));
		*(s->pstr++) = (char) (0x80 | ((utf32 >> 12) & 0x3f));
		*(s->pstr++) = (char) (0x80 | ((utf32 >> 6) & 0x3f));
		*(s->pstr++) = (char) (0x80 | (utf32 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy150:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych <= '7') goto yy155;
			if (yych <= '9') goto yy152;
			goto yy132;
		} else {
			if (yych <= 'F') goto yy152;
			if (yych <= '`') goto yy132;
			if (yych <= 'f') goto yy152;
			goto yy132;
		}
yy151:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy152;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy152:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy153;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy153:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 3);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) (0xc0 | (utf16 >> 6));
		*(s->pstr++) = (char) (0x80 | (utf16 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy155:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy132;
			if (yych >= ':') goto yy132;
		} else {
			if (yych <= 'F') goto yy156;
			if (yych <= '`') goto yy132;
			if (yych >= 'g') goto yy132;
		}
yy156:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 2);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) utf16;
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
	}


}

