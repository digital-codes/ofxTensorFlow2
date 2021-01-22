#include "ofApp.h"

#include "testOfxTF2Model.h"
#include "testofxTF2Tensor.h"
#include "testMemoryLayout.h"


//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetWindowTitle("test");


	// ==== Reference === //

	// create a tensor of an arbitrary shape and fill it
	auto input = cppflow::fill({1, 2, 2, 3}, 0.9f);
	// load the cppflow::model
	cppflow::model model(ofToDataPath("model"));
	// inference
	auto output = model(input);

	// print the tensor
	ofLog() << output;

	testOfxTF2Tensor();

	testOfxTF2Model(input, output);

	testMemoryLayout();

    ofExit(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}