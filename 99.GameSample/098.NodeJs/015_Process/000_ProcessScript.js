exports.log = function() {
    // console.log(format.apply(this, arguments) + '\n');
    process.stdout.write(format.apply(this, arguments) + '\n');
};

