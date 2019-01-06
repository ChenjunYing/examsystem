/*
Navicat MySQL Data Transfer

Source Server         : 3300
Source Server Version : 80013
Source Host           : localhost:3300
Source Database       : examsystem

Target Server Type    : MYSQL
Target Server Version : 80013
File Encoding         : 65001

Date: 2019-01-06 22:58:52
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `admin`
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `privilege` int(1) NOT NULL DEFAULT '0',
  `department` varchar(30) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('1', 'admin', 'admin', '0', '0');

-- ----------------------------
-- Table structure for `config`
-- ----------------------------
DROP TABLE IF EXISTS `config`;
CREATE TABLE `config` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `start_time` datetime DEFAULT NULL,
  `end_time` datetime DEFAULT NULL,
  `object_score` int(5) DEFAULT '0',
  `multi_score` int(5) DEFAULT NULL,
  `judge_score` int(5) DEFAULT '0',
  `is_submit` int(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `username` (`username`),
  KEY `exam_code` (`exam_code`),
  CONSTRAINT `config_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `config_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of config
-- ----------------------------
INSERT INTO `config` VALUES ('7', 'test', '8', null, null, '0', null, '0', '0');
INSERT INTO `config` VALUES ('8', 'test', '9', null, null, '0', null, '0', '0');

-- ----------------------------
-- Table structure for `exam`
-- ----------------------------
DROP TABLE IF EXISTS `exam`;
CREATE TABLE `exam` (
  `exam_code` int(5) NOT NULL AUTO_INCREMENT,
  `exam_name` varchar(40) NOT NULL,
  `start_time` datetime DEFAULT NULL,
  `end_time` datetime DEFAULT NULL,
  `duration` int(5) NOT NULL,
  `information` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`exam_code`),
  UNIQUE KEY `exam_code` (`exam_code`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of exam
-- ----------------------------
INSERT INTO `exam` VALUES ('8', '马原期末考试', null, null, '2', '马克思主义基本原理概论（2018版）');
INSERT INTO `exam` VALUES ('9', '面向对象的程序设计期末考试', null, null, '90', '1.考试时间：2019年1月23日\n2.考试地点：紫金港机房');

-- ----------------------------
-- Table structure for `exam_content`
-- ----------------------------
DROP TABLE IF EXISTS `exam_content`;
CREATE TABLE `exam_content` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `object_id` int(5) DEFAULT NULL,
  `judge_id` int(5) DEFAULT NULL,
  `exam_code` int(5) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `object_id` (`object_id`),
  KEY `subject_id` (`judge_id`),
  KEY `exam_code` (`exam_code`),
  CONSTRAINT `exam_content_ibfk_1` FOREIGN KEY (`object_id`) REFERENCES `object_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `exam_content_ibfk_2` FOREIGN KEY (`judge_id`) REFERENCES `judge_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `exam_content_ibfk_3` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of exam_content
-- ----------------------------
INSERT INTO `exam_content` VALUES ('12', '9', null, '8');
INSERT INTO `exam_content` VALUES ('13', '10', null, '8');
INSERT INTO `exam_content` VALUES ('14', '11', null, '8');
INSERT INTO `exam_content` VALUES ('15', '12', null, '8');
INSERT INTO `exam_content` VALUES ('16', '13', null, '8');
INSERT INTO `exam_content` VALUES ('17', '14', null, '8');
INSERT INTO `exam_content` VALUES ('18', '15', null, '8');
INSERT INTO `exam_content` VALUES ('19', '16', null, '8');
INSERT INTO `exam_content` VALUES ('20', null, '3', '8');
INSERT INTO `exam_content` VALUES ('21', null, '4', '8');
INSERT INTO `exam_content` VALUES ('22', null, '5', '8');
INSERT INTO `exam_content` VALUES ('23', null, '6', '8');
INSERT INTO `exam_content` VALUES ('24', null, '7', '8');
INSERT INTO `exam_content` VALUES ('25', '18', null, '9');
INSERT INTO `exam_content` VALUES ('26', '19', null, '9');
INSERT INTO `exam_content` VALUES ('27', '21', null, '9');
INSERT INTO `exam_content` VALUES ('28', '17', null, '9');
INSERT INTO `exam_content` VALUES ('29', '20', null, '9');
INSERT INTO `exam_content` VALUES ('30', null, '9', '9');
INSERT INTO `exam_content` VALUES ('31', null, '8', '9');

-- ----------------------------
-- Table structure for `judge_answer`
-- ----------------------------
DROP TABLE IF EXISTS `judge_answer`;
CREATE TABLE `judge_answer` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `question_id` int(5) NOT NULL,
  `answer` varchar(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `canswer` varchar(2) NOT NULL,
  `score` int(5) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `username` (`username`),
  KEY `exam_code` (`exam_code`),
  KEY `question_id` (`question_id`),
  CONSTRAINT `judge_answer_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `judge_answer_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `judge_answer_ibfk_3` FOREIGN KEY (`question_id`) REFERENCES `judge_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of judge_answer
-- ----------------------------

-- ----------------------------
-- Table structure for `judge_question`
-- ----------------------------
DROP TABLE IF EXISTS `judge_question`;
CREATE TABLE `judge_question` (
  `question_id` int(5) NOT NULL AUTO_INCREMENT,
  `description` varchar(800) NOT NULL,
  `answer` varchar(5) NOT NULL,
  `value` int(3) NOT NULL,
  `author` varchar(20) NOT NULL,
  PRIMARY KEY (`question_id`),
  UNIQUE KEY `question_id` (`question_id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of judge_question
-- ----------------------------
INSERT INTO `judge_question` VALUES ('3', '直接经验和间接经验的关系是认识中的“源”与“流”的关系', 'T', '1', 'admin');
INSERT INTO `judge_question` VALUES ('4', '意识决定物质', 'F', '1', 'admin');
INSERT INTO `judge_question` VALUES ('5', '矛盾具有普遍性和特殊性', 'T', '2', 'admin');
INSERT INTO `judge_question` VALUES ('6', '唯物主义辩证法的根本方法是逻辑推理法', 'F', '3', 'admin');
INSERT INTO `judge_question` VALUES ('7', '否定之否定规律揭示的事物发展的辩证形式是事物螺旋式上升或波浪式推进的过程', 'T', '1', 'admin');
INSERT INTO `judge_question` VALUES ('8', '抽象类中至少有一个纯虚函数', 'T', '2', 'admin');
INSERT INTO `judge_question` VALUES ('9', '该考试系统是使用IOpenGL和DevC++开发的', 'F', '1', 'admin');

-- ----------------------------
-- Table structure for `object_answer`
-- ----------------------------
DROP TABLE IF EXISTS `object_answer`;
CREATE TABLE `object_answer` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `exam_code` int(5) NOT NULL,
  `question_id` int(5) NOT NULL,
  `answer` varchar(5) NOT NULL,
  `canswer` varchar(5) NOT NULL,
  `score` int(5) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `username` (`username`),
  KEY `exam_code` (`exam_code`),
  KEY `question_id` (`question_id`),
  CONSTRAINT `object_answer_ibfk_1` FOREIGN KEY (`username`) REFERENCES `user` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `object_answer_ibfk_2` FOREIGN KEY (`exam_code`) REFERENCES `exam` (`exam_code`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `object_answer_ibfk_3` FOREIGN KEY (`question_id`) REFERENCES `object_question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of object_answer
-- ----------------------------

-- ----------------------------
-- Table structure for `object_question`
-- ----------------------------
DROP TABLE IF EXISTS `object_question`;
CREATE TABLE `object_question` (
  `question_id` int(5) NOT NULL AUTO_INCREMENT,
  `description` varchar(800) NOT NULL,
  `A` varchar(500) DEFAULT NULL,
  `B` varchar(500) DEFAULT NULL,
  `C` varchar(500) DEFAULT NULL,
  `D` varchar(500) DEFAULT NULL,
  `answer` varchar(5) NOT NULL,
  `value` int(3) NOT NULL,
  `type` int(1) NOT NULL DEFAULT '0',
  `author` varchar(20) NOT NULL,
  PRIMARY KEY (`question_id`),
  UNIQUE KEY `question_id` (`question_id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of object_question
-- ----------------------------
INSERT INTO `object_question` VALUES ('9', ' 真理的绝对性是指它的（   ）', '永恒性', '客观性', '不变性', '终极性', 'B', '2', '0', 'admin');
INSERT INTO `object_question` VALUES ('10', '否定之否定仿佛是向肯定的复归，这种观点是（  ）', '折中主义', '辩证法', '诡辩论', '形而上学', 'B', '1', '0', 'admin');
INSERT INTO `object_question` VALUES ('11', '真理是（   ）', '客观事物及其规律', '对人们有用的认识', '人们对客观事物及其规律的正确反映', '为大多数人普遍接受的思想', 'C', '2', '0', 'admin');
INSERT INTO `object_question` VALUES ('12', '人类全部社会关系中最基础的关系是（   ）', '血缘关系', '生产关系', '政治关系', '伦理关系', 'B', '3', '0', 'admin');
INSERT INTO `object_question` VALUES ('13', '下列活动中，属于最基本的实践活动的是（   ）', '农民播种小麦', '医生给病人做手术', '法官审理案件', '科学家进行化学实验', 'A', '1', '0', 'admin');
INSERT INTO `object_question` VALUES ('14', '真哩具有（   ）', '客观性', '绝对性', '相对性', '普遍性', 'ABC', '1', '1', 'admin');
INSERT INTO `object_question` VALUES ('15', '下列不属于物质的本质特性是（   ）', '客观实在性', '实物性', '结构性', '可分性', 'BCD', '2', '1', 'admin');
INSERT INTO `object_question` VALUES ('16', '下列关于物质和运动的叙述中正确的是（   ）', '运动是绝对的', '物质是运动的本质', '空间是物质运动的存在形式', '无条件的绝对运动和有条件的相对静止构成了对立统一的关系', 'AD', '3', '1', 'admin');
INSERT INTO `object_question` VALUES ('17', '下列属于面向对象程序设计的基本特征的是（   ）', '封装', '继承', '多态', '重载', 'ABC', '2', '1', 'admin');
INSERT INTO `object_question` VALUES ('18', '以下程序运行的结果是（   ）\ninclude<iostream>\nusing namespace std;\nint main(){\n    cout<<\"HelloWorld\"<<endl;\n    return 0;\n}', 'Hello?', 'Hello World', 'HelloWorld', 'HelloWorld!', 'C', '3', '0', 'admin');
INSERT INTO `object_question` VALUES ('19', 'C++在字符串中str中获取下标为i的字符正确的方法是（  ）', 'str.charAt(i)', 'str.i', 'str->i', 'str.at(i)', 'D', '1', '0', 'admin');
INSERT INTO `object_question` VALUES ('20', 'C++中在字符串str后追加字符串ss正确的方法是（   ）', 'str = str + ss;', 'str.append(ss);', 'strcpy(ss,str);', 'strcmp(ss,str);', 'AB', '4', '1', 'admin');
INSERT INTO `object_question` VALUES ('21', 'C++中virtual关键字表示（   ）', '一个整形数', '没有任何意义', '虚函数', '纯虚函数', 'C', '1', '0', 'admin');

-- ----------------------------
-- Table structure for `user`
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `privilege` int(1) NOT NULL DEFAULT '0',
  `person_name` varchar(15) NOT NULL,
  `major` varchar(10) NOT NULL,
  `phone_number` varchar(15) NOT NULL,
  `sex` int(1) NOT NULL DEFAULT '0',
  `student_id` varchar(15) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('1', 'test', '123', '0', '嘤菜鸡', '软件工程', '12345678901', '0', '3170103456');
