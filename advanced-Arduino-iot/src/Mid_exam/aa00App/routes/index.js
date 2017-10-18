var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express App by AA00, 이상훈' });
});

/* GET myInfo page, by /aann -> multi-routing */
router.get('/aa00', function(req, res, next) {
  res.render('aa00app', { title: 'Express Server by AA00',
  						   id: 'AA00',
  						   name: '컴시' });
  // views/aannapp.jade
});

/* GET myInfo page, by /aann -> multi-routing */
router.get('/aa00exam', function(req, res, next) {
  res.render('aa00exam', { title: 'Exam. on node.js express server',
  						   id: 'AA00',
  						   name: '컴시' });
  // views/aa00exam.jade
});
module.exports = router;
