--TEST--
Bug #61978 (Object recursion not detected for classes that implement JsonSerializable)
--SKIPIF--
<?php if (!extension_loaded("jsond")) print "skip"; ?>
--FILE--
<?php

class JsonTest1 {
    public $test;
    public $me;
    public function __construct() {
        $this->test = '123';
        $this->me  = $this;
    }
}

class JsonTest2 implements JsondSerializable {
    public $test;
    public function __construct() {
        $this->test = '123';
    }
    public function jsonSerialize() {
        return array(
            'test' => $this->test,
            'me'   => $this
        );
    }
}


$obj1 = new JsonTest1();
var_dump(jsond_encode($obj1, JSOND_PARTIAL_OUTPUT_ON_ERROR));

echo "==\n";

$obj2 = new JsonTest2();
var_dump(jsond_encode($obj2, JSOND_PARTIAL_OUTPUT_ON_ERROR));

?>
--EXPECTF--
string(44) "{"test":"123","me":{"test":"123","me":null}}"
==
string(44) "{"test":"123","me":{"test":"123","me":null}}"
