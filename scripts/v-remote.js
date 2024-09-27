const { execSync } = require('child_process');
const args = process.argv.slice(2);

const submodule = args[0] || 'all';

try {
  if (submodule === 'all') {
    console.log('Pulling all submodules...');
    execSync('git submodule update --remote --merge', { stdio: 'inherit' });
  } else {
    console.log(`Pulling submodule: ${submodule}`);
    execSync(`git submodule update --remote --merge ${submodule}`, {
      stdio: 'inherit',
    });
  }
} catch (error) {
  console.error(`Error pulling submodule: ${error.message}`);
}
